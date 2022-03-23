#include "binary_trees.h"

/**
* binary_trees_ancestor - function that finds the lowest common ancestor
*	of two nodes
*
* @first: pointer to the first node
* @second: pointer to the second node
*
* Return:
*	pointer to the lowest common ancestor node
*	NULL if no common ancestor
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *second_tmp = second;

	if (!first)
		return (NULL);

	while (second_tmp != NULL)
	{
		if (first == second_tmp)
			return ((binary_tree_t *)first);

		second_tmp = second_tmp->parent;
	}

	return (binary_trees_ancestor(first->parent, second));
}
