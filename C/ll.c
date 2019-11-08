#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "ll.h"

int 		DEBUG = 0;

/* free _whole_ list */
void
ll_free(ll_node * l)
{
	if (l->next != NULL)
		ll_free(l->next);
	if (DEBUG)
		printf("free node:%s\n", l->val);
	ll_free1(l);
}

void
ll_free1(ll_node * n)
{
	free(n->val);
	free(n);
}

/* return 0 for equal */
int
ll_cmp(ll_node * n1, ll_node * n2)
{
	if ((n1 == NULL) || (n2 == NULL))
		return -2;
	return strcmp(n1->val, n2->val);
}

/*
 * take _1st_match_ node out of list return 0 for success
 */
int
ll_rm(ll_node ** l, char *v)
{
	ll_node        *ip, *i;

	ip = NULL;
	i = *l;

	do {
		if (DEBUG && (ip != NULL))
			printf("ip->val:%s\n", ip->val);
		if (DEBUG)
			printf("i->val:%s\n", i->val);

		if (strcmp(i->val, v) == 0) {
			if (DEBUG)
				printf("DEL %s\n", i->val);
			if (ip == NULL) {
				if (DEBUG)
					printf("1st node so...\n");
				*l = i->next;
				ll_free1(i);
				return 2;
			} else {
				if (DEBUG)
					printf("del by rearrange linke ...\n");
				ip->next = i->next;
				ll_free1(i);
				return 1;
			}
		}
		ip = i;
		i = i->next;
	} while (i != NULL);

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
	ll_free1(l);
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
	n->next = NULL;
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
	int 		len = 1;
	if (l == NULL)
		return 0;
	while (l->next != NULL) {
		len++;
		l = l->next;
	}
	return len;
}

ll_node        *
ll_makelist(int count,...)
{
	ll_node        *h;
	ll_node        *n;
	va_list 	args;
	char           *v;

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
