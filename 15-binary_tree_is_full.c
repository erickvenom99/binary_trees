#include "binary_trees.h"
/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    int left_t, right_t = 0;
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		left_t = binary_tree_is_full(tree->left);
		right_t = binary_tree_is_full(tree->right);
		return (left_t && right_t);
	}

	return (0);
}