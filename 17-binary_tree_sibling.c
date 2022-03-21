#include "binary_trees.h"

/**
* binary_tree_sibling - Return the sibling of a node
*
* @node: The node to get the sibbling
*
* Return: Pointer to the node sibbling, NULL else
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
	{
		if (node->parent->right)
			return (node->parent->right);
	}
	else
	{
		if (node->parent->left)
			return (node->parent->left);
	}

	return (NULL);
}
