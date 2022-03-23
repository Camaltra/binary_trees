#include "binary_trees.h"

/**
* bst_search - Search a value into the BST
*
* @tree: Pointer to the root node
* @value: Value to search
*
* Return: Return pointer to the founded node
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
