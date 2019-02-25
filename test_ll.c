#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ll.h"

void
test1()
{
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
}

void
test_ll_makelist()
{
	ll_node		*l;
	l = ll_makelist(3, "1", "2", "3");
	ll_print(l);
}

void
test_ll_cmp()
{
	ll_node		*n1, *n2;
	n1 = ll_mknode("2");
	n2 = ll_mknode("2");
	if ((n1 == NULL) || (n2 == NULL)) {
		printf("error in ll_mknode\n");
		return;
	}
	printf("ll_cmp %s %s : %d\n", n1->val, n2->val, ll_cmp(n1, n2));
	ll_free(n2);
	n2 = NULL;
	printf("ll_cmp %s %s : %d\n", n1->val, NULL, ll_cmp(n1, n2));
}

void
test_ll_rm()
{
	ll_node		*l;

	l = ll_makelist(3, "1", "2", "3");
	printf("========orig:\n");
	ll_print(l);
	printf("ll_rm 1 : ret:%d\n", ll_rm(&l, "1"));	
	printf("after rm:\n");
	ll_print(l);
	printf("\n");

	ll_free(l);
	l = ll_makelist(3, "1", "2", "3");
	printf("---------orig:\n");
	ll_print(l);
	printf("ll_rm 2 : ret:%d\n", ll_rm(&l, "2"));	
	printf("after rm:\n");
	ll_print(l);
	printf("\n");
}

void
test_ptr2struct(ll_node *n1, ll_node *n2)
{
 	/* point n1 to n2 ? */
	n1 = n2;
	printf("n1->val:%s\n", n1->val);
}

int
main()
{
	printf("ll test\n");
	printf("------------------------------\n");

/*
	test1();
	test_ll_makelist();
	test_ll_cmp(); 
*/

	test_ll_rm();

/*
	ll_node		*n1, *n2;
	n1 = ll_mknode("n1");
	n2 = ll_mknode("n2");
	test_ptr2struct(n1, n2);
	printf("n1->val:%s\n", n1->val);
*/

	return EXIT_SUCCESS;
}

