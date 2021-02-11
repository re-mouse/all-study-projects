#include "ft_btree.h"
#include <stdio.h>
#include <string.h>

void	btree_insert_data(t_btree **r, void *i, int (*cmp)(const char *, const char *));

int	btree_level_count(t_btree *root);

void	*btree_search_item(t_btree *r, void *d, int (*c)(void *, void *));

t_btree	*btree_create_node(void *item);

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

int		main()
{
	t_btree **r;
	t_btree *test;
	
	r = malloc(sizeof(t_btree*));
	test = btree_create_node("4");
	*r = test;
	test->right = btree_create_node("2");
	test->left = btree_create_node("1");
	test->left->left = btree_create_node("3");
	test->right->right = btree_create_node("4");
	test->right->right->left = btree_create_node("5");
	btree_apply_prefix(test, printf);
	int b = btree_level_count(test);
	printf("lvl = %d", b);
}