#include "binary_trees.h"

/**
* binary_tree_height - function that measures the height of a binary tree
*
* @tree: pointer to the root node of the tree to measure the height
*
* Return:
*	height of the tree
*   0 if tree == NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int heightLeft = 0, heightRight = 0;

	if (!tree)
		return (-1);

	heightLeft = binary_tree_height(tree->left);
	heightRight = binary_tree_height(tree->right);

	if (heightLeft > heightRight)
		return (heightLeft + 1);
	else
		return (heightRight + 1);
}
