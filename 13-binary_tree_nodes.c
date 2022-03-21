#include "binary_trees.h"

/**
* binary_tree_nodes - Count the number of nodes inside a tree
*
* @tree: Pointer to the tree
*
* Return: The number of nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);

	return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}
