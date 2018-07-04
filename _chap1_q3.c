#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char    *URLify(const char *);
int      count_spaces(const char *);
char    *copy_add_trailing_spaces(const char *, int);
void	 teststuff();
void	 push_right(char *, int, int, int); 

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

    char * s1 = copy_add_trailing_spaces(words[0], count_spaces(words[0]));
 	push_right(s1, 3, 2, strlen(words[0])); // push right 2 spaces at index 3
	printf("[%s]PUSH_RIGHT[%s]", words[0], s1);

    for (int i=0; i<nwords; i++) {
	    printf("word[%s] url[%s]\n", words[i], URLify(words[i]));
    }    

	return 0;
}

void	
teststuff() 
{
	printf("\n");
	printf("sizeof('\\0'):%lu\n", sizeof('\0'));
	printf("sizeof(char):%lu\n", sizeof(char));
	printf("sizeof('a'):%lu\n", sizeof('a'));
	printf("\n");
}

char *
URLify(const char * s) 
{
	char * u;
	int orig_len;

    u = copy_add_trailing_spaces(s, count_spaces(s));

	for (int i=0; i<strlen(s); i++) {
		/*
		printf("[%c]", u[i]); 
		if (u[i] == ' ') {
			printf("SPACE");
		}
		*/
		
	}	
	printf("\n");

	return u;
}

int 
count_spaces(const char * s) 
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
copy_add_trailing_spaces(const char * s, int spaces) 
{
	int nspaces, len;
    char * copy;

	nspaces = count_spaces(s);
    /* len = (strlen(s) + (2*nspaces) + 1) * sizeof(char); */
    len = strlen(s) + (2*nspaces) + 1;
    copy = malloc(len);

    strlcpy(copy, s, len);
    for (int i=0; i<nspaces; i++) {
        strlcat(copy, "  ", len);
    }
    /* printf("copy[%s] tried for length:%d copy length:%zu\n", copy, len, strlen(copy)); */
    return copy;
}

/*
 * Move all characters in the string to the right by 'count' spaces.
 * Do this at location 'loc'.
 */
void
push_right(char * s, int loc, int count, int orig_len) {
	printf("loc:%d count:%d orig_len:%d\n", loc, count, orig_len);
	  
}

