#include "binary_trees.h"

/**
* binary_tree_uncle - function that finds the uncle of a node
*
* @node: pointer to the root node of the tree to measure the height
*
* Return:
*	a pointer to the uncle node
*	NULL if no uncle
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *tmp;

	if (node && node->parent && node->parent->parent)
	{
		tmp = node->parent;
		node = tmp->parent;
		if (node->right == tmp)
			return (node->left);
		return (node->right);
	}

	return (NULL);
}
