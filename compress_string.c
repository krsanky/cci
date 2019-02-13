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
	char		tmp[100];
	
	prev = s[0];
	prev_count = 0;
	cl = 5 * strlen(s);
	*c = calloc(cl, cl*sizeof('a'));
	if (*c == NULL)
		return -1;
	strlcpy(*c, "", cl); /* overkill to make sure valid null terminated string? */
	for (unsigned long i=1; i<strlen(s)+1; i++) {
		//printf("%2lu:%c prev:%c\n", i, s[i], prev);
		if ((prev == s[i]) && (i<strlen(s))) {
			prev_count += 1;
		} else {
			tmp[0] = '\0';
			snprintf(tmp, 99, "%c", prev);
			//printf("tmp:%s\n", tmp);
			strlcat(*c, tmp, cl);
			tmp[0] = '\0';
			snprintf(tmp, 99, "%d", prev_count+1);
			//printf("-tmp:%s\n", tmp);
			strlcat(*c, tmp, cl);
			prev_count = 0;
		}
		if (i<strlen(s)) 
			prev = s[i];
	}

	//printf("c:%s\n", *c);
	if (strlen(s) <= strlen(*c))
		return 1;
	return 0;
}

int 
main() 
{
	char		s1[] = "aabcccccaaa";
	char		s1_out[] = "a2b1c5a3";
	char		s2[] = "asdqqwe";
	char		s2_out[] = "a1s1d1q2w1e1";
	char		s3[] = "SLKwwQQap";
	char		s3_out[] = "S1L1K1w2Q2a1p1";
	char		*c;
	int		ret;

	ret = compress_string(s1, &c);
	printf("s:%s ret:%d c:%s exp:%s\n", s1, ret, c, s1_out);
	ret = compress_string(s2, &c);
	printf("s:%s ret:%d c:%s exp:%s\n", s2, ret, c, s2_out);
	ret = compress_string(s3, &c);
	printf("s:%s ret:%d c:%s exp:%s\n", s3, ret, c, s3_out);

	return EXIT_SUCCESS;
}

