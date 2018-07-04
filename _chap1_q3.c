#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void     URLify(char *);
int      count_spaces(char *);
char    *copy_add_trailing_spaces(char *, int);

/* 
 * All major routines should have a comment briefly describing what 
 * they do.  The comment before the "main" routine should describe 
 * what the program does. 
 */ 
int 
main(int argc, char * argv[]) 
{
	//printf("%s: num-args:%d\n", argv[0], argc);
    
	size_t nwords;

    char * words[] = {
	    "str str str",
	    "test string 1",
	    "asd 1 23",
	    "SSSS GGGG JJJJ",
	    "q  weq  we",
	    "d fsW ",
        "asd 123  2 3 4",
	    "A",
	    "a top"
	};
    nwords = sizeof(words)/sizeof(words[0]);
	
	//URLify(s2);
	//URLify(s7);
    printf("1st word:%zu array of words:%zu\n", sizeof(words[0]), nwords);

    for (int i=0; i<nwords; i++) {
	    URLify(words[i]);
        /* printf("word[%s]\n", words[i]); */
    }    

	return 0;
}

void 
URLify(char * s) 
{
	int first;
	size_t last;

	first = 0;
	last = strlen(s);

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

/*
 * https://man.openbsd.org/strlcpy.3
 * https://www.sudo.ws/todd/papers/strlcpy.html
 */
char *
copy_add_trailing_spaces(char * s, int spaces) 
{
	int nspaces, len;
    char * copy;

	nspaces = count_spaces(s);
    len = ((strlen(s) + nspaces) * sizeof(char)) + 1; // +1 for null terminator?
    copy = malloc(len);

    strlcpy(copy, s, len);
    for (int i=0; i<nspaces; i++) {
        strlcat(copy, " ", len);
    }
    printf("copy[%s] tried for length:%d copy length:%zu\n", copy, len, strlen(copy));
    return copy;
}


