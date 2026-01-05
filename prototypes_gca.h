#ifndef _PROTOTYPES_GCA_H_
#define _PROTOTYPES_GCA_H_

#ifndef _POINTER_DEF_
#define _POINTER_DEF_
#ifdef X3J11
typedef void    *pointer;               /* generic pointer type */
#else
typedef char    *pointer;               /* generic pointer type */
#endif
#undef POINTER
#define POINTER pointer
#endif	/* _POINTER_DEF_ */

/* alloca and xmalloc */
extern void *alloca(unsigned size);
extern void *xmalloc(int size);
extern void *xrealloc(void *old, int size);
extern void *xcalloc(int number, int size);

/* obstack */
void _obstack_begin(void* inpH, int size, int alignment, POINTER* chunkfun* freefun);
void _obstack_newchunk(void* inpH, int length);
int _obstack_allocated_p(struct obstack* h, POINTER obj);
void obstack_free(struct obstack* h, POINTER obj h, obj);
void _obstack_free(struct obstack* h, POINTER obj);
int POINTER(int obstack_base, struct obstack);
int POINTER(int obstack_next_free, struct obstack);
int ( obstack_object_size )(struct obstack);
int ( obstack_room )(struct obstack);
void ( obstack_grow )(struct obstack, POINTER pointer, int length);
void ( obstack_grow0 )(struct obstack, POINTER pointer, int length);
void ( obstack_1grow )(struct obstack, int character);
void ( obstack_blank )(struct obstack, int length);
void ( obstack_1grow_fast )(struct obstack, int character);
void ( obstack_blank_fast )(struct obstack, int length);
int POINTER(int obstack_finish, struct obstack);
int POINTER(int obstack_alloc, struct obstack, int length);
int POINTER(int obstack_copy, struct obstack, POINTER pointer, int length);
int POINTER(int obstack_copy0, struct obstack, POINTER pointer, int length);

#endif	/* _PROTOTYPES_GCA_H_ */
