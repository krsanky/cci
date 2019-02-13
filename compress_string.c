#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * return 0 success
 *        1 s <= c
 *        -1 error
 */
int
compress_string(const char *s, char **c)
{
	char		prev;
	int		prev_count;
	int		cl;
	int		cidx;
	char		tmp[100];
	
	prev = s[0];
	prev_count = 0;
	cl = 5 * strlen(s);
	*c = malloc(cl);
	if (*c == NULL)
		return -1;
	(*c)[0] = '\0';
	cidx = 0;

	for (int i=1; i<strlen(s); i++) {
		printf("%2d:%c prev:%c\n", i, s[i], prev);
		if (prev == s[i]) {
			prev_count += 1;
		} else {
			(*c)[cidx] = s[i];
			cidx += 1;
			(*c)[cidx] = '\0';
			if (prev_count > 0) {
				tmp[0] = '\0';
				snprintf(tmp, 99, "%d", prev_count);
				strlcat(*c, tmp, cl);
			}
		}

		prev = s[i];
	}

	printf("c:%s\n", *c);
	*c = NULL;
	return 0;
}

int 
main() 
{
	char		s1[] = "aabcccccaaa";
	char		*c;
	char		s1_out[] = "a2b1c5a3";
	int		ret;

	ret = compress_string(s1, &c);
	printf("s:%s c:%s\n", s1, c);

	char		buf[100];
	strlcpy(buf, "asdasd...", 100);
	printf("buf:%s\n", buf);

	return EXIT_SUCCESS;
}

