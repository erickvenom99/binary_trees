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

/**
 * binary_t_depth - nodes depth from root
 * @tree: node check depth of tree
 * Return: 0 if it is the root or number of depth
 */
size_t binary_t_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree && tree->parent)
	{
		depth = 1 + binary_t_depth(tree->parent);
		return (depth);
	}
	else
	{
		return (0);
	}
}


/**
 * link_tree_node - linked list from depth level and node
 * @head: head of node
 * @tree: node to store
 * @value: depth of node
 * Return: void
 */
void link_tree_node(link_node **head, const binary_tree_t *tree, size_t value)
{
	link_node *temp, *new_node;

	new_node = malloc(sizeof(link_node));
	if (new_node == NULL)
	{
		return;
	}
	new_node->n = value;
	new_node->node = tree;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new_node->next = NULL;
		temp->next = new_node;
	}
}

/**
 * recall - goes through the complete tree and each stores each node
 * in linked_node function
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: Nothing by default it affects the pointer
 */
void recall(link_node **head, const binary_tree_t *tree)
{
	size_t value = 0;

	if (tree != NULL)
	{
		value = binary_t_depth(tree);
		link_tree_node(head, tree, value);
		recall(head, tree->left);
		recall(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_node *head, *temp;
	size_t counts = 0, height = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recall(&head, tree);
		while (counts <= height)
		{
			temp = head;
			while (temp != NULL)
			{
				if (counts == temp->n)
				{
					func(temp->node->n);
				}
				temp = temp->next;
			}
			counts++;
		}
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
}
