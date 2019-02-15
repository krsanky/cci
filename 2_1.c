#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ll.h"

int 
main() 
{
	printf("remove dupes\n");

	ll_node		*n;
	ll_node		*l;
	long		r;

	l = ll_mknode("node 1 -- head");
	if (l == NULL)
		return EXIT_FAILURE;
	for (int i=0; i<20; i++) {
		r = random();
		printf("rand:%ld\n", r);

		n = ll_mknode("node 2");

		if (n != NULL)
			ll_append(l, n);

	}

	ll_print(l);
	ll_free(l);
	return EXIT_SUCCESS;
}

