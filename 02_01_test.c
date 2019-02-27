#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "ll.h"
#include "02.h"

void
print_head_dupes(ll_node * l)
{
	if (l->next != NULL)
		printf("noop\n");
}

ll_node        *
build_list(int len)
{
	ll_node        *n;
	ll_node        *l;
	long 		r;
	char 		buf      [20];

	srandom(time(NULL));
	r = random() % 100;
	snprintf(buf, 20, "%ld", r);

	l = ll_mknode(buf);
	if (l == NULL)
		return NULL;

	for (int i = 0; i < len; i++) {
		r = random() % 100;
		snprintf(buf, 20, "%ld", r);
		/* printf("rand:%ld as-str:%s\n", r, buf); */

		n = ll_mknode(buf);
		if (n != NULL)
			ll_append(l, n);
	}

	return l;
}

int
main()
{
	int 		list_length = 10;
	ll_node        *l;

	printf("02_01_test.c\n");
	printf("remove dupes\n");

	if ((l = build_list(list_length)) == NULL)
		/*
		 * if ((l = ll_makelist(6, "1", "2", "1", "2", "3", "3")) ==
		 * NULL)
		 */
		return EXIT_FAILURE;

	printf("* ll length:%d\n", ll_length(l));
	ll_print(l);

	rm_dupes(l);

	printf("- ll length:%d\n", ll_length(l));
	ll_print(l);

	ll_free(l);
	return EXIT_SUCCESS;
}
