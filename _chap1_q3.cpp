#include <stdio.h>
#include <string.h>

void URLify(char *);
int count_spaces(char *);

int main(int argc, char * argv[]) {
	//printf("%s: num-args:%d\n", argv[0], argc);
/*
	char s1[] = "str str str    ";
	char s2[] = "test string 1    ";
	char s3[] = "asd 1 23    ";
	char s4[] = "q  weq  we        ";
	char s5[] = "d fsW  ";
	char s6[] = "A  ";
*/
	char s1[] = "str str str";
	char s2[] = "test string 1";
	char s3[] = "asd 1 23";
	char s4[] = "q  weq  we";
	char s5[] = "d fsW ";
	char s6[] = "A";
	//URLify(s1);
	URLify(s2);
	//URLify(s3);

	return 0;
}

void URLify(char * s) {
	int first = 0;
	size_t last = strlen(s);
	printf("URLify:[%s] length:%zu\n", s, last);
	//for (int i=0; i<last; i++) printf("%2d: %c\n", i, s[i]);

	printf("num spaces:%d\n", count_spaces(s));
	
}

int count_spaces(char * s) {
    int n = 0;
	for (int i=0; i<strlen(s); i++) {
		if (s[i] == ' ') {
            n++;
        }
    }
    return n;
}

