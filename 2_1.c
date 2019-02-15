#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "ll.h"

ll_node *
build_list(int len)
{
	ll_node		*n;
	ll_node		*l;
	long		r;
	char		buf[20];

	srandom(time(NULL));
	r = random() % 100;
	snprintf(buf, 20, "%ld", r);

	l = ll_mknode(buf);
	if (l == NULL)
		return NULL;

	for (int i=0; i<len; i++) {
		r = random() % 100;
		snprintf(buf, 20, "%ld", r);
/*		printf("rand:%ld as-str:%s\n", r, buf);*/

		n = ll_mknode(buf);
		if (n != NULL)
			ll_append(l, n);
	}

	return l;
}

void
rm_head_dupes(ll_node *l)
{
	ll_node		*h;
	h = l;
	while (l->next != NULL) {
/*		printf("strcmp: %s %s\n", h->val, l->next->val);*/
		if ((strcmp(h->val, l->next->val) == 0)) {
			printf("MATCH: %s %s\n", h->val, l->next->val);
		}
		l = l->next;
	}
}

int 
main() 
{
	ll_node		*l;

	printf("remove dupes\n");
	if ((l = build_list(200)) == NULL)
		return EXIT_FAILURE;
	rm_head_dupes(l);
/*	ll_print(l);*/
	ll_free(l);
	return EXIT_SUCCESS;
}

