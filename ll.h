typedef struct ll_node ll_node;
struct ll_node {
	char           *val;
	ll_node        *next;
};

void 		ll_free  (ll_node *);
void 		ll_deltail(ll_node *);
void 		ll_print (ll_node *);
ll_node        *ll_mknode(char *);
void 		ll_append(ll_node *, ll_node *);
int 		ll_length (ll_node *);

/*
ll_node * ll_first();
ll_node * ll_last();
*/
