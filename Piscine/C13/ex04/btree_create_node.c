#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = malloc(sizeof(t_btree));
	tree->item = item;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}
