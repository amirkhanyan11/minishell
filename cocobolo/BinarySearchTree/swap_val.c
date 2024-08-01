
#include "tree.h"


void swap_val(tree_node *lhv, tree_node *rhv)
{
	if (!rhv || !lhv) return;

	int tmp = rhv->val;
	rhv->val = lhv->val;
	lhv->val = tmp;
}
