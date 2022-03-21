#include "binary_trees.h"

/**
* binary_tree_is_root - Check if a node is a root
*
* @node: Node to check
*
* Return: 1 if a node is a root, 0 else
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent)
		return (0);
	else
		return (1);
}
