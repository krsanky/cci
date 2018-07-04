#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void URLify(char *);
int count_spaces(char *);
void allocate_test();
char * copy_add_trailing_spaces(char *, int);

int 
main(int argc, char * argv[]) 
{
	//printf("%s: num-args:%d\n", argv[0], argc);
    
    char * words[] = {
	    "str str str",
	    "test string 1",
	    "asd 1 23",
	    "q  weq  we",
	    "d fsW ",
        "asd 123  2 3 4",
	    "A",
	    "a top"};
	
	//URLify(s2);
	//URLify(s7);
    printf("1st word:%zu array of words:%zu\n", sizeof(words[0]), sizeof(words)/sizeof(words[0]));

	allocate_test();
	return 0;
}

void 
URLify(char * s) 
{
	int first = 0;
	size_t last = strlen(s);
	printf("URLify:[%s] length:%zu\n", s, last);
	//for (int i=0; i<last; i++) printf("%2d: %c\n", i, s[i]);

	printf("num spaces:%d\n", count_spaces(s));
    char * cpy = copy_add_trailing_spaces(s, 4);
    free(cpy);
	
}

int 
count_spaces(char * s) 
{
    int n = 0;
	for (int i=0; i<strlen(s); i++) {
		if (s[i] == ' ') {
            n++;
        }
    }
    return n;
}

void 
allocate_test() 
{
	int *array = malloc(10 * sizeof(int));
	if (array == NULL) {
		fprintf(stderr, "malloc failed\n");
	    //return(-1);
	}
	free(array);
}

// https://man.openbsd.org/strlcpy.3
// https://www.sudo.ws/todd/papers/strlcpy.html
char *
copy_add_trailing_spaces(char * s, int spaces) 
{
	int nspaces = count_spaces(s);
    int len = ((strlen(s) + nspaces) * sizeof(char)) + 1; // +1 for null terminator?
    char * copy = malloc(len);

    strlcpy(copy, s, len);
    for (int i=0; i<nspaces; i++) {
        strlcat(copy, "X", len);
    }
    printf("copy[%s] tried for length:%d copy length:%zu\n", copy, len, strlen(copy));
    return copy;
}


