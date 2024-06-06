#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Points tree root node
 *
 * Return: size of the binary tree, or 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size = 0;
	size_t size = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	size = left_size + right_size + 1;
	return (size);
}
