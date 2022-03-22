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

	if (tree->right)
		heightRight = 1 + binary_tree_height(tree->right);

	if (heightLeft > heightRight)
		return (heightLeft);
	return (heightRight);
}

/**
* binary_tree_size - Count the size of a binary tree
*
* @tree: Pointer to the binary tree
*
* Return: The size of the binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
* _pow - The classical pow function
*
* @a: int
* @b: int
*
* Return: The pow A power B
*/
int _pow(int a, int b)
{
	if (b == 0)
		return (1);

	return (a * _pow(a, b - 1));
}

/**
* binary_tree_is_perfect - Check if a binary tree is perfect
*
* @tree: Pointer to the tree
*
* Return: 1 if is perfect, 0 else.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int heightTree, numOfNodes;

	heightTree = binary_tree_height(tree);
	numOfNodes = binary_tree_size(tree);

	if (numOfNodes == (_pow(2, heightTree + 1) - 1))
		return (1);

	return (0);
}
