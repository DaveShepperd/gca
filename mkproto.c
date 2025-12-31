/* mkproto.c - Generate ANSI C function prototypes from C source files
 * Handles both K&R and ANSI C style function definitions
 * Emits prototypes for global (non-static) functions only
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 8192
#define MAX_BUFFER 32768
#define MAX_PARAMS 32
#define MAX_TOKEN 256

typedef struct {
    char type[MAX_TOKEN];
    char name[MAX_TOKEN];
} Param;

/* Remove C comments from a string */
static void strip_comments(char *str)
{
    char *src = str;
    char *dst = str;

    while (*src) {
        if (src[0] == '/' && src[1] == '*') {
            src += 2;
            while (*src && !(src[0] == '*' && src[1] == '/'))
                src++;
            if (*src) src += 2;
            *dst++ = ' ';  /* Replace comment with space */
        } else if (src[0] == '/' && src[1] == '/') {
            /* C++ comment - rest of line */
            *dst = '\0';
            return;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
}

/* Check if a line starts with static */
static int is_static(const char *str)
{
    while (*str && isspace(*str))
        str++;
    return strncmp(str, "static", 6) == 0 && (isspace(str[6]) || !str[6]);
}

/* Check if a line starts with struct/union/enum */
static int is_struct_union_enum(const char *str)
{
    while (*str && isspace(*str))
        str++;

    if (strncmp(str, "struct", 6) == 0 && (isspace(str[6]) || !str[6]))
        return 1;
    if (strncmp(str, "union", 5) == 0 && (isspace(str[5]) || !str[5]))
        return 1;
    if (strncmp(str, "enum", 4) == 0 && (isspace(str[4]) || !str[4]))
        return 1;
    if (strncmp(str, "typedef", 7) == 0 && (isspace(str[7]) || !str[7]))
        return 1;

    return 0;
}

/* Simple tokenizer */
static char *next_token(char **str_ptr, char *token)
{
    char *p = *str_ptr;

    /* Skip whitespace */
    while (*p && isspace(*p))
        p++;

    if (!*p) {
        *str_ptr = p;
        token[0] = '\0';
        return token;
    }

    /* Single character tokens */
    if (strchr("(){}[];,*&", *p)) {
        token[0] = *p++;
        token[1] = '\0';
        *str_ptr = p;
        return token;
    }

    /* Identifiers */
    if (isalpha(*p) || *p == '_') {
        int i = 0;
        while ((isalnum(*p) || *p == '_') && i < MAX_TOKEN - 1)
            token[i++] = *p++;
        token[i] = '\0';
        *str_ptr = p;
        return token;
    }

    /* Other */
    token[0] = *p++;
    token[1] = '\0';
    *str_ptr = p;
    return token;
}

/* Check if a word is a type keyword */
static int is_type_keyword(const char *word)
{
    static const char *keywords[] = {
        "void", "char", "short", "int", "long", "float", "double",
        "signed", "unsigned", "struct", "union", "enum",
        "const", "volatile", "register", "auto", "extern",
        NULL
    };
    int i;

    for (i = 0; keywords[i]; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

/* Check if a word is a C keyword (not just type keywords) */
static int is_c_keyword(const char *word)
{
    static const char *keywords[] = {
        "if", "else", "while", "for", "do", "switch", "case", "default",
        "break", "continue", "return", "goto", "sizeof", "typedef",
        NULL
    };
    int i;

    if (is_type_keyword(word))
        return 1;

    for (i = 0; keywords[i]; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

/* Parse and emit function prototype */
static void process_function(char *text)
{
    char *p = text;
    char token[MAX_TOKEN];
    char return_type[MAX_LINE] = "";
    char func_name[MAX_TOKEN] = "";
    char params[MAX_LINE] = "";
    char kr_decls[MAX_LINE] = "";
    int in_params = 0;
    int paren_depth = 0;
    int after_params = 0;
    int is_kr = 0;
    Param kr_params[MAX_PARAMS];
    int num_kr_params = 0;
    char *param_copy;
    char *tok_ptr;
    char tok[MAX_TOKEN];
    int has_types = 0;
    char *kr_ptr;
    char type_buf[MAX_LINE];
    int collecting_type;
    int i, found;

    strip_comments(text);

    /* Parse the function signature */
    p = text;
    while (*p) {
        next_token(&p, token);
        if (!token[0])
            break;

        if (strcmp(token, "{") == 0) {
            /* Start of function body */
            break;
        } else if (strcmp(token, "(") == 0 && func_name[0]) {
            in_params = 1;
            paren_depth = 1;
        } else if (in_params) {
            if (strcmp(token, "(") == 0) {
                paren_depth++;
                if (params[0]) strcat(params, " ");
                strcat(params, token);
            } else if (strcmp(token, ")") == 0) {
                paren_depth--;
                if (paren_depth == 0) {
                    in_params = 0;
                    after_params = 1;
                } else {
                    if (params[0]) strcat(params, " ");
                    strcat(params, token);
                }
            } else {
                if (params[0] && strcmp(token, "*") != 0 && strcmp(token, ",") != 0)
                    strcat(params, " ");
                strcat(params, token);
            }
        } else if (after_params) {
            /* Collecting K&R declarations */
            if (kr_decls[0] && strcmp(token, "*") != 0 && strcmp(token, ";") != 0)
                strcat(kr_decls, " ");
            strcat(kr_decls, token);
        } else {
            /* Building return type and function name */
            if (func_name[0]) {
                if (return_type[0] && strcmp(func_name, "*") != 0)
                    strcat(return_type, " ");
                strcat(return_type, func_name);
            }

            if (is_type_keyword(token) || strcmp(token, "*") == 0) {
                if (return_type[0] && strcmp(token, "*") != 0)
                    strcat(return_type, " ");
                strcat(return_type, token);
                func_name[0] = '\0';
            } else {
                strcpy(func_name, token);
            }
        }
    }

    /* Default return type */
    if (!return_type[0])
        strcpy(return_type, "int");

    if (!func_name[0])
        return;

    /* Skip if function name is a C keyword */
    if (is_c_keyword(func_name))
        return;

    /* Determine if this is K&R style or ANSI style */
    if (params[0] && strcmp(params, "void") != 0) {
        /* Check if params contains type keywords - if not, it's K&R */
        param_copy = strdup(params);
        tok_ptr = param_copy;
        has_types = 0;

        while (*next_token(&tok_ptr, tok)) {
            if (is_type_keyword(tok) || strcmp(tok, "*") == 0) {
                has_types = 1;
                break;
            }
        }
        free(param_copy);

        if (!has_types && kr_decls[0]) {
            /* K&R style - parse parameter names and declarations */
            is_kr = 1;

            /* Extract parameter names from params */
            param_copy = strdup(params);
            tok_ptr = param_copy;
            while (*next_token(&tok_ptr, tok)) {
                if (strcmp(tok, ",") == 0)
                    continue;
                if (num_kr_params < MAX_PARAMS) {
                    strcpy(kr_params[num_kr_params].name, tok);
                    strcpy(kr_params[num_kr_params].type, "int"); /* default */
                    num_kr_params++;
                }
            }
            free(param_copy);

            /* Parse K&R declarations to get types */
            kr_ptr = kr_decls;
            type_buf[0] = '\0';
            collecting_type = 1;

            while (*next_token(&kr_ptr, tok)) {
                if (strcmp(tok, ";") == 0) {
                    type_buf[0] = '\0';
                    collecting_type = 1;
                } else if (strcmp(tok, ",") == 0) {
                    /* Same type, next parameter */
                    collecting_type = 0;
                } else {
                    /* Check if this token is a parameter name */
                    found = 0;
                    for (i = 0; i < num_kr_params; i++) {
                        if (strcmp(kr_params[i].name, tok) == 0) {
                            if (type_buf[0]) {
                                strcpy(kr_params[i].type, type_buf);
                            }
                            found = 1;
                            collecting_type = 0;
                            break;
                        }
                    }

                    if (!found && collecting_type) {
                        /* Part of the type */
                        if (type_buf[0] && strcmp(tok, "*") != 0)
                            strcat(type_buf, " ");
                        strcat(type_buf, tok);
                    }
                }
            }
        }
    }

    /* Output the prototype */
    printf("%s %s(", return_type, func_name);

    if (!params[0] || strcmp(params, "void") == 0) {
        printf("void");
    } else if (is_kr) {
        /* Output K&R params with types */
        for (i = 0; i < num_kr_params; i++) {
            printf("%s %s", kr_params[i].type, kr_params[i].name);
            if (i < num_kr_params - 1)
                printf(", ");
        }
    } else {
        /* ANSI style - output as-is */
        printf("%s", params);
    }

    printf(");\n");
}

int main(int argc, char **argv)
{
    FILE *fp;
    char line[MAX_LINE];
    char buffer[MAX_BUFFER];
    int in_comment = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    buffer[0] = '\0';

    while (fgets(line, sizeof(line), fp)) {
        char cleaned[MAX_LINE];
        char *src = line;
        char *dst = cleaned;

        /* Handle multi-line comments and strip them */
        while (*src) {
            if (!in_comment && src[0] == '/' && src[1] == '*') {
                in_comment = 1;
                src += 2;
                *dst++ = ' ';  /* Replace with space */
                continue;
            }
            if (in_comment) {
                if (src[0] == '*' && src[1] == '/') {
                    in_comment = 0;
                    src += 2;
                    continue;
                }
                src++;
                continue;
            }
            *dst++ = *src++;
        }
        *dst = '\0';

        /* Skip if still in comment */
        if (in_comment)
            continue;

        /* Now work with cleaned line */
        char *trimmed = cleaned;
        while (*trimmed && isspace(*trimmed))
            trimmed++;

        /* Skip preprocessor directives (including multi-line ones) */
        if (*trimmed == '#') {
            /* Check if line ends with backslash (continuation) */
            char *end = cleaned + strlen(cleaned) - 1;
            while (end > cleaned && isspace(*end))
                end--;

            /* If ends with backslash, keep skipping lines until no continuation */
            while (*end == '\\') {
                if (!fgets(line, sizeof(line), fp))
                    break;
                /* Find end of new line */
                end = line + strlen(line) - 1;
                while (end > line && isspace(*end))
                    end--;
            }
            continue;
        }

        /* Skip empty lines */
        if (!*trimmed || *trimmed == '\n')
            continue;

        /* Start of a potential declaration */
        if (buffer[0] == '\0') {
            /* Skip struct/union/enum definitions */
            if (is_struct_union_enum(cleaned))
                continue;

            /* Skip lines that are just closing braces */
            char *p = trimmed;
            if (*p == '}' && (p[1] == '\0' || p[1] == '\n'))
                continue;

            /* Must look like it could be a function */
            /* Skip if it has an '=' (likely variable assignment) */
            if (strchr(cleaned, '=') && !strchr(cleaned, '('))
                continue;

            /* Skip if it's just a variable declaration (ends with ; and no parens before it) */
            char *paren = strchr(cleaned, '(');
            char *semi = strchr(cleaned, ';');
            if (semi && !paren)
                continue;
        }

        /* Accumulate line into buffer */
        if (buffer[0] && buffer[strlen(buffer) - 1] != ' ' && !isspace(cleaned[0]))
            strcat(buffer, " ");
        strcat(buffer, cleaned);

        /* Check for end of declaration/definition */
        if (strchr(buffer, '{')) {
            /* Potential function definition - check if it really looks like one */
            if (strchr(buffer, '(') && strchr(buffer, ')')) {
                /* Check if it's static - if so, skip it */
                if (!is_static(buffer)) {
                    process_function(buffer);
                }

                /* Skip the function body (whether static or not) */
                int brace_depth = 1;
                int c;
                while (brace_depth > 0 && (c = fgetc(fp)) != EOF) {
                    if (c == '{')
                        brace_depth++;
                    else if (c == '}')
                        brace_depth--;
                }

                /* Consume rest of line to sync with line boundaries */
                while ((c = fgetc(fp)) != EOF && c != '\n')
                    ;
            }

            buffer[0] = '\0';
        } else if (strchr(buffer, ';')) {
            /* Semicolon found - check if it's a declaration or K&R param decls */
            /* If the buffer ends with ");", it's a forward declaration - reset */
            /* Otherwise, if it has '(' and ')', it's K&R style - keep accumulating */
            char *end = buffer + strlen(buffer) - 1;
            while (end > buffer && isspace(*end))
                end--;

            if (*end == ';' && end > buffer && *(end-1) == ')') {
                /* Ends with ");", it's a declaration */
                buffer[0] = '\0';
            } else if (!strchr(buffer, '(') || !strchr(buffer, ')')) {
                /* No function signature, just a declaration */
                buffer[0] = '\0';
            }
            /* Otherwise, keep accumulating (K&R parameter declarations) */
        }

        /* Prevent buffer overflow */
        if (strlen(buffer) > MAX_BUFFER - MAX_LINE - 100)
            buffer[0] = '\0';
    }

    fclose(fp);
    return 0;
}
