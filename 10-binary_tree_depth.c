#include "binary_trees.h"

/**
* binary_tree_depth - Mesure the depth of a tree
*
* @tree: Pointer to the tree
*
* Return: The depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
		return (0);
	if (tree->parent)
		count++;

	return (binary_tree_depth(tree->parent) + count);
}
