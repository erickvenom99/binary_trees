#include "binary_trees.h"
/**
 * binary_tree_height -  height of a binary tree
 * @tree: Points to the root node
 *
 * Return: height of the binary tree, or 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_tree = 0;
	size_t right_tree = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left)
		{
			left_tree = 1 + binary_tree_height(tree->left);
		}
		else
		{
			left_tree = 0;
		}
		if (tree->right)
		{
			right_tree = 1 + binary_tree_height(tree->right);
		}
		else
		{
			right_tree = 0;
		}
		if (left_tree > right_tree)
		{
			return (left_tree);
		}
		else
		{
			return (right_tree);
		}
	}
}
