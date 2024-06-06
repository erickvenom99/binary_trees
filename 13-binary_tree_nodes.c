#include "binary_trees.h"
/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Points
 *
 * Return: Number of nodes with at least 1 child in tree,
 * or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		count += ((tree->left || tree->right) ? 1 : 0);
		count += binary_tree_nodes(tree->left);
		count += binary_tree_nodes(tree->right);
		return (count);
	}
}
