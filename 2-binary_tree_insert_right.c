#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts new node at the left-child o parent node
 * @parent: Points to the node
 * @value: Value of new node
 *
 * Return: Points created node, or NULL if failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t  *newnode;

	if (parent == NULL)
	{
		return (NULL);
	}
	newnode = binary_tree_node(parent, value);
	if (newnode == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		newnode->right = parent->right;
		parent->right->parent = newnode;
	}
	parent->right = newnode;
	return (newnode);
}
