#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char    *URLify(const char *);
int      count_spaces(const char *);
char    *copy_add_trailing_spaces(const char *, int);
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

    char * w2 = "WORD TWO";
    char * s2 = copy_add_trailing_spaces(w2, count_spaces(w2)*2);
    printf("s2[%s]\n", s2);
    push_right(s2, 4, 10, 2);
    printf("s2[%s]\n", s2);

    /*
    for (int i=0; i<nwords; i++) {
        copy_add_trailing_spaces(words[i], count_spaces(words[i])*2);
        //printf("word[%s] url[%s]\n", words[i], URLify(words[i]));
    }*/

	return 0;
}

char *
URLify(const char * s) 
{
	char * u;
	int orig_len, end_cap;

    orig_len = end_cap = strlen(s);
    u = copy_add_trailing_spaces(s, count_spaces(s));
    printf("u[%s]\n", u);

	for (int i=0; i<strlen(u)-1; i++) {
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
 * Return copy of 's' with 'spaces' number of spaces
 * added to the end.
 */
char *
copy_add_trailing_spaces(const char * s, int spaces) 
{
	int len;
    char * copy;

    len = strlen(s) + spaces + 1;
    copy = malloc(len);

    strlcpy(copy, s, len);
    for (int i=0; i<spaces; i++) {
        strlcat(copy, " ", len);
    }
    printf("orig[%s] copy[%s] length(incl. NUL):%d strlen(copy):%zu\n", s, copy, len, strlen(copy)); 
    return copy;
}

/* 
 * Move the sub-string [start, end] to the right by 'count' spaces.
 */
void
push_right(char * s, int start, int end, int count) {
    for (int i=end; i>start; i--)  
        s[i+count] = s[i];
}

