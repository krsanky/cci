#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "ll.h"

int 		DEBUG = 0;

/* free list */
void
ll_free(ll_node * l)
{
	if (l->next != NULL)
		ll_free(l->next);
	if (DEBUG)
		printf("free node:%s\n", l->val);
	free(l->val);
	free(l);
}

/* return 0 for equal */
int
ll_cmp(ll_node * n1, ll_node * n2)
{
	if ((n1 == NULL) || (n2 == NULL))
		return 1;

	return 1;

}

/* take node out of list */
int
ll_rm(ll_node * l, ll_node * n)
{
	while (l->next != NULL) {
		printf("l->val:%s\n", l->val);
	}
	return 0;
}

void
ll_deltail(ll_node * l)
{
	ll_node        *p = NULL;

	while (l->next != NULL) {
		p = l;
		l = l->next;
	}
	if (p != NULL)
		p->next = NULL;
	free(l);
}

void
_print(ll_node * l, int idx)
{
	printf("%d:%s\n", idx, l->val);
	if (l->next != NULL) {
		_print(l->next, ++idx);
	}
}
void
ll_print(ll_node * l)
{
	_print(l, 0);
}

ll_node        *
ll_mknode(char *v)
{
	ll_node        *n = NULL;

	n = malloc(sizeof(ll_node));
	if (n != NULL) {
		n->val = strdup(v);
		if (n->val == NULL)
			free(n);
	}
	return n;
}

void
ll_append(ll_node * l, ll_node * n)
{
	while (l->next != NULL)
		l = l->next;
	l->next = n;
}

int
ll_length(ll_node * l)
{
	int 		len = 0;
	while (l->next != NULL) {
		len++;
		l = l->next;
	}
	return len;
}

ll_node		*
ll_make_list(int  count,...)
{
	ll_node 	*h;
	ll_node 	*n;
	va_list		args;
	char		*v;
	
	va_start(args, count);  
	v = va_arg(args, char *);
	if (DEBUG)
		printf("v1:%s\n", v);
	h = ll_mknode(v);
	if (h == NULL)
		return NULL;

	for (int i = 1; i < count; i++) {
		v = va_arg(args, char *);
		if (DEBUG)
			printf("i:%d arg:%s\n", i, v);
		n = ll_mknode(v);
		if (n == NULL)
			return NULL;
		ll_append(h, n);
	}

	va_end(args);

	return h;
}



