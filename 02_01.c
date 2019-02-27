#include <stdio.h>
#include <string.h>

#include "ll.h"
#include "02.h"

void
rm_head_dupes(ll_node * l)
{
	ll_node        *h;
	ll_node        *i, *iprev;
	ll_node        *d;

	if (l == NULL)
		return;
	if (ll_length(l) < 2)
		return;

	h = l;
	iprev = h;
	i = h->next;

	while (i != NULL) {
		if (strcmp(h->val, i->val) == 0) {
			iprev->next = i->next;
			ll_free1(i);
		}
		iprev = i;
		i = i->next;
	}
}

void
rm_dupes(ll_node * l)
{
	while (l != NULL) {
		rm_head_dupes(l);
		l = l->next;
	}

}
