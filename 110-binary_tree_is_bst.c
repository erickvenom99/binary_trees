#include "binary_trees.h"
/**
 * left_subtree - Checks if the left subtree of a binary search tree
 *                satisfies the binary search tree property.
 * @node: Pointer to the current node in the binary tree.
 * @max_value: Maximum value allowed in the left subtree.
 *
 * Return: 1 if the left subtree satisfies the binary search tree property,
 *         0 otherwise.
 */
int left_subtree(const binary_tree_t *node, int max_value)
{
	int left_node = 0, right_node = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max_value)
			return (0);
		left_node = left_subtree(node->left, max_value);
		right_node = left_subtree(node->right, max_value);
		return ((left_node == right_node && left_node == 1) ? 1 : 0);
	}
}


/**
 * right_subtree - Checks if the right subtree of a binary search tree
 *                 satisfies the binary search tree property.
 * @node: Pointer to the current node in the binary tree.
 * @min_value: Minimum value allowed in the right subtree.
 *
 * Return: 1 if the right subtree satisfies the binary search tree property,
 *         0 otherwise.
 */
int right_subtree(const binary_tree_t *node, int min_value)
{
	int left_node = 0, right_node = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min_value)
			return (0);
		left_node = right_subtree(node->left, min_value);
		right_node = right_subtree(node->right, min_value);
		return ((left_node == right_node && left_node == 1) ? 1 : 0);
	}
}

/**
*binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
*@tree: Pointer to the root node of the binary tree.
*
*Return: 1 if the binary tree is a valid binary search tree, 0 otherwise.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_node = 1, right_node = 1;

	if (tree == NULL)
		return (1);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->right)
	{
		if (!right_subtree(tree->right, tree->n))
			return (0);
		right_node = binary_tree_is_bst(tree->right);
	}
	if (tree->left)
	{
		if (!left_subtree(tree->left, tree->n))
			return (0);
		left_node = binary_tree_is_bst(tree->left);
	}
	return (left_node && right_node);
}
