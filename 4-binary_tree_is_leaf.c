#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Finds external node or leaf node
 * @node: node
 * Return: 1 if leaf or 0 if it is not
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}
