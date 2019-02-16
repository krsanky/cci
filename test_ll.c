#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ll.h"

int
main()
{
	printf("ll test\n");

	ll_node        *l;
	ll_node        *n2;
	ll_node        *n3;

	l = ll_mknode("node 1 -- head");
	n2 = ll_mknode("node 2");
	n3 = ll_mknode("node 3");
	if ((l != NULL) && (n2 != NULL) && (n3 != NULL)) {
		ll_append(l, n2);
		ll_append(l, n3);
		ll_print(l);
		//ll_deltail(l);
		ll_print(l);
	} else {
		printf("error making ll_node(s)\n");
	}
	ll_free(l);

	return EXIT_SUCCESS;
}
