#include "binary_trees.h"
/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: A pointer to the first node.
* @second: A pointer to the second node.
* Return: A pointer to the lowest common ancestor node, or NULL if either
*
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *left_lca, *right_lca;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *) first);

	left_lca = (binary_tree_t *) first->parent;
	right_lca = (binary_tree_t *) second->parent;

	if (!left_lca || first == right_lca || (!left_lca->parent && right_lca))
		return (binary_trees_ancestor(first, right_lca));
	else if (!right_lca || left_lca == second ||
		 (!right_lca->parent && left_lca))
		return (binary_trees_ancestor(left_lca, second));

	return (binary_trees_ancestor(left_lca, right_lca));
}
