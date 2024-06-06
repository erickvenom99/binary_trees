#include "binary_trees.h"
/**
 * binary_tree_is_root -Finds if a node is a root in a binary tree.
 * @node: Points to the node.
 *
 * Return: 1 node is a root, 0 otherwise.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
