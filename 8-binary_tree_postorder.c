#include "binary_trees.h"
/**
 * binary_tree_postorder - Post-order traversal of a binary tree
 * @tree: Points the root node
 * @func: Points to function called
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
