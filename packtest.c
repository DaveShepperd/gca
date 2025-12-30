static char *rcsid = "@(#)$Header: /pdsrc/Local/RCS/packtest.c,v 1.1 90/04/26 17:50:35 root Exp $";

/*
 * Regression test to check that gcc's #pragma pack() support does the
 * same thing as Microsoft C's.
 *
 * Run with this command from sh, not csh, since SCO's csh is BROKEN.
 * cc packtest.c && ./a.out > m && gcc packtest.c && ./a.out > g && diff m g
 * You should not see any output.
 *
 * $Log:	packtest.c,v $
 * Revision 1.1  90/04/26  17:50:35  root
 * Initial revision
 * 
 */

#pragma pack(4)
struct s1 {
	char one;
	int  two;
	long three;
	double four;
} s1;
#pragma pack(2)
struct s2 {
	char one;
	int  two;
	long three;
	double four;
} s2;
#pragma pack(1)
struct s3 {
	char one;
	int  two;
	long three;
	double four;
} s3;
#pragma pack()
struct s4 {
	char one;
	int  two;
	long three;
	double four;
} s4;
struct biggie {
	struct s3 x1;
	struct s1 b1;
	struct s3 x2;
	struct s2 b2;
	struct s3 x3;
	struct s3 b3;
	struct s3 x4;
	struct s4 b4;
} b;
#define offsetof(TYPE, MEMBER) ((unsigned) &((TYPE *)0)->MEMBER)
main()
{
	printf("% 4d% 4d% 4d\n",
		offsetof(struct s1, two),
		offsetof(struct s1, three),
		offsetof(struct s1, four));
	printf("% 4d% 4d% 4d\n",
		offsetof(struct s2, two),
		offsetof(struct s2, three),
		offsetof(struct s2, four));
	printf("% 4d% 4d% 4d\n",
		offsetof(struct s3, two),
		offsetof(struct s3, three),
		offsetof(struct s3, four));
	printf("% 4d% 4d% 4d\n",
		offsetof(struct s4, two),
		offsetof(struct s4, three),
		offsetof(struct s4, four));
	printf("\n% 4d% 4d% 4d\n",
		((char *)&b.b1.two) - ((char *)&b.b1.one),
		((char *)&b.b1.three) - ((char *)&b.b1.one),
		((char *)&b.b1.four) - ((char *)&b.b1.one));
	printf("% 4d% 4d% 4d\n",
		((char *)&b.b2.two) - ((char *)&b.b2.one),
		((char *)&b.b2.three) - ((char *)&b.b2.one),
		((char *)&b.b2.four) - ((char *)&b.b2.one));
	printf("% 4d% 4d% 4d\n",
		((char *)&b.b3.two) - ((char *)&b.b3.one),
		((char *)&b.b3.three) - ((char *)&b.b3.one),
		((char *)&b.b3.four) - ((char *)&b.b3.one));
	printf("% 4d% 4d% 4d\n\n",
		((char *)&b.b4.two) - ((char *)&b.b4.one),
		((char *)&b.b4.three) - ((char *)&b.b4.one),
		((char *)&b.b4.four) - ((char *)&b.b4.one));
	printf("    % 4d% 4d\n", sizeof b.b1, (char *)&b.b1 - (char *)&b);
	printf("    % 4d% 4d\n", sizeof b.b2, (char *)&b.b2 - (char *)&b);
	printf("    % 4d% 4d\n", sizeof b.b3, (char *)&b.b3 - (char *)&b);
	printf("    % 4d% 4d\n", sizeof b.b4, (char *)&b.b4 - (char *)&b);
	exit(0);
}
