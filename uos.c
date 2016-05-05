#include <stdio.h>

typedef enum { EMPTY, INTS, FLOATS, CHARS, DOUBLES } stype;

typedef struct {
	int a, b, c;
} ints_t;

typedef struct {
	float a, b, c;
} floats_t;

typedef struct {
	char a, b, c, d,
		 e, f, g, h,
		 i, j, k, l;
} chars_t;

typedef struct {
	double a, b;
} doubles_t;

typedef struct {
	stype type;
	char *name;
	union {
		ints_t    ints;
		floats_t  floats;
		chars_t   chars;
		doubles_t doubles;
	} ;
} uos_t;

void print_uos(uos_t uos) {
	printf("Item \"%s\":\n", uos.name);
	switch (uos.type) {
		case INTS:
			printf("\ta: 0x%x\n\tb: 0x%x\n\tc: 0x%x\n",
					uos.ints.a, uos.ints.b, uos.ints.c);
			break;

		case CHARS:
			printf( "\ta: %c\tb: %c\tc: %c\td: %c\n"
					"\te: %c\tf: %c\tg: %c\th: %c\n"
					"\ti: %c\tj: %c\tk: %c\tl: %c\n",
					uos.chars.a, uos.chars.b, uos.chars.c, uos.chars.d,
					uos.chars.e, uos.chars.f, uos.chars.g, uos.chars.h,
					uos.chars.i, uos.chars.j, uos.chars.k, uos.chars.l);
			break;

		case FLOATS:
			printf("\ta: %.24f\n\tb: %.24f\n\tc: %.24f\n",
					uos.floats.a, uos.floats.b, uos.floats.c);
			break;

		case DOUBLES:
			printf("\ta: %.43f\n\tb: %.43f\n",
					uos.doubles.a, uos.doubles.b);
			break;

		case EMPTY:
		default:
			break;
	}
	puts("");
}

int main(int argc, char** argv) {
	uos_t unions_of_structs[10];
	int i = 0;

	unions_of_structs[i].type    = INTS;
	unions_of_structs[i].name    = "hexes";
	unions_of_structs[i].ints.a  = 0x1337;
	unions_of_structs[i].ints.b  = 0x509;
	unions_of_structs[i].ints.c  = -42;
	++i;

	unions_of_structs[i].type    = INTS;
	unions_of_structs[i].name    = "alphas as ints";
	unions_of_structs[i].ints.a  = 'a';
	unions_of_structs[i].ints.b  = 'b';
	unions_of_structs[i].ints.c  = 'c';
	++i;

	unions_of_structs[i].type    = CHARS;
	unions_of_structs[i].name    = "alphas as chars";
	unions_of_structs[i].chars.a = 'A';
	unions_of_structs[i].chars.b = 'B';
	unions_of_structs[i].chars.c = 'C';
	unions_of_structs[i].chars.d = 'D';
	unions_of_structs[i].chars.e = 'E';
	unions_of_structs[i].chars.f = 'F';
	unions_of_structs[i].chars.g = 'G';
	unions_of_structs[i].chars.h = 'H';
	unions_of_structs[i].chars.i = 'I';
	unions_of_structs[i].chars.j = 'J';
	unions_of_structs[i].chars.k = 'K';
	unions_of_structs[i].chars.l = 'L';
	++i;

	unions_of_structs[i].type     = FLOATS;
	unions_of_structs[i].name     = "floaty";
	unions_of_structs[i].floats.a = 1.0;
	unions_of_structs[i].floats.b = 1.0e10;
	unions_of_structs[i].floats.c = 1.0e20;
	++i;

	unions_of_structs[i].type     = FLOATS;
	unions_of_structs[i].name     = "pi, e, prime constant as floats";
	unions_of_structs[i].floats.a = 3.14159265358979323846264338327950288419716939937510;
    //                              3.141592741012573242187500000000
	//                                      ^
	unions_of_structs[i].floats.b = 2.71828182845904523536028747135266249775724709369995;
    //                              2.718281745910644531250000000000
	//                                      ^
	unions_of_structs[i].floats.c = 0.41468250985111166024810962215430770836577423813791;
    //                              0.414682507514953613281250000000
	//                                        ^
	++i;

	unions_of_structs[i].type      = DOUBLES;
	unions_of_structs[i].name      = "pi, e as doubles";
	unions_of_structs[i].doubles.a = 3.14159265358979323846264338327950288419716939937510;
    //                               3.1415926535897931159979634685441851615905760
	//                                                ^
	unions_of_structs[i].doubles.b = 2.71828182845904523536028747135266249775724709369995;
    //                               2.7182818284590450907955982984276488423347470
	//                                                ^
	++i;

	unions_of_structs[i].type      = DOUBLES;
	unions_of_structs[i].name      = "prime constant, 1/9 as doubles";
	unions_of_structs[i].doubles.a = 0.41468250985111166024810962215430770836577423813791;
    //                               0.4146825098511116580723978586320299655199050
	//                                                 ^
	unions_of_structs[i].doubles.b = 1.0f / 9.0f;
    //                               0.1111111119389533996582031250000000000000000
	//                                          ^
	++i;

	unions_of_structs[i].type      = EMPTY;

	printf( "sizeof uos_t = %zd\n"
			"sizeof unions_of_structs = %zd\n\n", sizeof unions_of_structs[0],
			sizeof unions_of_structs);
	for (i = 0; unions_of_structs[i].type != EMPTY; ++i)
		print_uos(unions_of_structs[i]);

	return 0;
}
