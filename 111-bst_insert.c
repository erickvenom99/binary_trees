#include "binary_trees.h"
/**
 * bst_insert - Inserts a new node in a BST
 * @tree: Double pointer to the root of the BST
 * @value: Value to be inserted into the BST
 *
 * Return: Pointer to newly inserted node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, current;
	binary_tree_t *tree_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		tree_node = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)tree_node;
		*tree = new;
	}
	else
	{
		current = *tree;
		if (current->n < value)
		{
			if (current->right)
				new = bst_insert(&current->right, value);
			else
			{
				tree_node = binary_tree_node((binary_tree_t *)
							     current, value);
				current->right = (bst_t *)tree_node;
				new = current->right;
			}
		}
		else if (current->n > value)
		{
			if (current->left)
				new = bst_insert(&current->left, value);
			else
			{
				tree_node = binary_tree_node((binary_tree_t *)
							     current, value);
				current->left = (bst_t *)tree_node;
				new = current->left;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
