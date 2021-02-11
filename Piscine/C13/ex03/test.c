#include "bt_bree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = malloc(sizeof(t_btree));
	tree->item = item;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}

int	main()
{
	t_btree *test;
	
	test = btree_create_node("asd\n");
	test->right = btree_create_node("fda\n");
	test->left = btree_create_node("qwe\n");
	test->left->left = btree_create_node("fgfa\n");
	test->right->right = btree_create_node("qweoja\n");
	btree_apply_suffix(test, &printf);
}