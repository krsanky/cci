#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char    *URLify(const char *);
int      count_spaces(const char *);
char    *copy_add_trailing_spaces(const char *, int);
void	 teststuff();
void	 push_right(char *, int, int, int); 

bool debug = false;

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


    char * s1 = copy_add_trailing_spaces(words[1], count_spaces(words[1]));
    push_right(s1, 4, 10, 2);

    for (int i=0; i<nwords; i++) 
        printf("word[%s] url[%s]\n", words[i], URLify(words[i]));

	return 0;
}

char *
URLify(const char * s) 
{
	char * u;
	int orig_len, end_cap;

    orig_len = end_cap = strlen(s);
    u = copy_add_trailing_spaces(s, count_spaces(s));

	for (int i=0; i<strlen(s); i++) {
		printf("[%c]", u[i]); 
		if (u[i] == ' ') {
			printf("SPACE");
            push_right(u, i, end_cap, 2);
            end_cap = end_cap + 2;
            u[i] = '/';
            u[i+1] = '|';
            u[i+2] = '\\';
		}
		/*
        _ _ _ _ _ _ _ _ _ _ _ _ _
	    t e s t * s t r i n g   1
        _ _ _ _ _ _ _ _ _ _ _ _ _|_ _ _ _

        at the asterisk*, move the remaining string(up to end_cap) 2 spaces to the right 
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
 * Move the sub-string [start, end] to the right by 'count' spaces.
 *
[test string 1    ]
[XXXX stringXXXXXX]
 */
void
push_right(char * s, int start, int end, int count) {
    if (debug) {
	    printf("[%s]\n", s);
	    printf("[");
        for (int i=0; i<strlen(s); i++) {
            if ((i<start) || (i>end)) 
                printf("%c", 'X');
            else
                printf("%c", s[i]);
        }
	    printf("]\n");
    }
	  
    for (int i=end; i>start; i--) { 
        s[i+count] = s[i];
    }
    if (debug) printf("[%s]\n", s);
}

