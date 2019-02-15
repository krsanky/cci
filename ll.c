#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ll.h"

int DEBUG = 0;

void
ll_free(ll_node *l)
{
	if (l->next != NULL)
		ll_free(l->next);
	if (DEBUG) 
		printf("free node:%s\n", l->val);
	free(l->val);
	free(l);
}

void
ll_deltail(ll_node *l)
{
	ll_node		*p = NULL;

	while (l->next != NULL) {
		p = l;
		l = l->next;
	}
	if (p != NULL) 
		p->next = NULL;
	free(l);
}

void
_print(ll_node *l, int idx)
{
	printf("%d:%s\n", idx, l->val);
	if (l->next != NULL) {
		_print(l->next, ++idx);
	}
}
void
ll_print(ll_node *l)
{
	_print(l, 0);
}

ll_node *
ll_mknode(char *v)
{
	ll_node		*n;

	n = malloc(sizeof(ll_node));
	if (n != NULL) {
		n->val = strdup(v);	
		if (n->val == NULL)
			free(n);
	}

	return n;
}

void
ll_append(ll_node *l, ll_node *n)
{
	while(l->next != NULL)
		l = l->next;
	l->next = n;
}


