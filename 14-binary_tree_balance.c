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
		return (0);

	if (tree->left)
		heightLeft = 1 + binary_tree_height(tree->left);
	else
		heightLeft = 1;

	if (tree->right)
		heightRight = 1 + binary_tree_height(tree->right);
	else
		heightRight = 1;

	if (heightLeft > heightRight)
		return (heightLeft);
	return (heightRight);
}


/**
* binary_tree_balance - function that measures the balance factor
*   of a binary tree
*
* @tree: pointer to the root node of the tree to measure the balance factor
*
* Return:
*	balance factor of the binary tree
*   0 if tree == NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
