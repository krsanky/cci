#include <stdio.h>
#include <string.h>

void URLify(char *);
int find_first_space(char *);
int find_first_space_buffer(char *);

int main(int argc, char * argv[]) {
	//printf("%s: num-args:%d\n", argv[0], argc);

	char s1[] = "str str str    ";
	char s2[] = "test string 1    ";
	char s3[] = "asd 1 23    ";
	char s4[] = "q  weq  we        ";
	char s5[] = "d fsW  ";
	char s6[] = "A  ";
	//if (strlen(s) > 1) s[1] = 'X';

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

	printf("1st space buf:%d\n", find_first_space_buffer(s));
	
	printf("space at: %d\n", find_first_space(s));
	printf("shift string over 2...\n");
	
}

int find_first_space_buffer(char * s) {
	for (int i=strlen(s)-1; i>=0; i--) {
		printf("%2d: %c\n", i, s[i]);
		if (s[i] != ' ') {
			//printf("no space?\n");
			return i;
		}
	}
	return -1;
}

int find_first_space(char * s) {
	for (int i=0; i<strlen(s); i++) 
		if (s[i] == ' ') 
			return i;
	return -1;
}


