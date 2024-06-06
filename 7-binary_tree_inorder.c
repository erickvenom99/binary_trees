#include "binary_trees.h"
/**
 * binary_tree_inorder - In-order traversal of a binary tree
 * @tree: Points root node of the binary tree
 * @func: Points to a function call for each node
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
