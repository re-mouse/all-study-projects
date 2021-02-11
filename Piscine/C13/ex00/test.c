#include "bt_bree.h"
#include "btree_create_node.c"

int	main()
{
	t_btree *test;
	
	test = btree_create_node("asd");
	test->right = btree_create_node("fda");
	test->left = btree_create_node("qwe");
	test->left->left = btree_create_node("fgfa");
	test->right->right = btree_create_node("qweoja");
}