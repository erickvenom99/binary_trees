#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Performs left-rotation on a binary tree
 * @tree: pointers to the root node
 *
 * Return: points to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *p;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	p = tree->right;
	tree->right = p->left;
	if (p->left != NULL)
	{
		p->left->parent = tree;
	}
	p->left = tree;
	p->parent = tree->parent;
	tree->parent = p;
	return (p);
}
