#include <stdio.h>
#include <string.h>

#include "ll.h"
#include "02.h"

void
rm_head_dupes(ll_node * l)
{
	ll_node        *h;
	ll_node        *del;

	h = l;

	while (l->next != NULL) {
		/* printf("strcmp: %s %s\n", h->val, l->next->val); */
		if ((strcmp(h->val, l->next->val) == 0)) {
			printf("MATCH: %s %s\n", h->val, l->next->val);
			/* del the node l->next from list */
			del = l->next;
			l->next = l->next->next;
			del->next = NULL;
			ll_free(del);
		}
		l = l->next;
	}
}
