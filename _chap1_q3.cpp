#include <stdio.h>
#include <string.h>

void s1();
void URLify(char *);

int main(int argc, char * argv[]) {
	//printf("%s: num-args:%d\n", argv[0], argc);
	// 	ss := []string{"asd 1 23    ", "q  weq  we        ", "d fsW  "}
	s1();
	char s2[] = "test string 1  ";
	URLify(s2);
	return 0;
}

void URLify(char * s) {
	s[1] = 'x';
	printf("URLify:[%s] length:%zu\n", s, strlen(s));
	for (int i=0; i<strlen(s); i++) {
		printf("%2d:%c\n", i, s[i]);

	}
}


void s1() {
	char ch_arr[3][10] = {
    	"spike",
		"tom",
		"jerry"
	};
/*
	char *sports[] = {
		"golf",
		"hockey",
		"football",
		"cricket",
		"shooting"
	};
*/
}


