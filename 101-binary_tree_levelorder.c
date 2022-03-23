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
* printCurrentLevel - Print the current level
*
* @root: Pointer to the root node of the tree
* @level: The level of the tree
* @func: Function to print the value
*
* Return: Anything, cause void function
*/
void printCurrentLevel(const binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1, func);
		printCurrentLevel(root->right, level - 1, func);
	}
}

/**
* binary_tree_levelorder - Print the binary tree in the level order
*
* @tree: Pointer to the tree
* @func: The function to print the value in this case
*
* Return: Anything, cause void function
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height;
	int i;

	if (tree == NULL || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 1; i <= height; i++)
		printCurrentLevel(tree, i, func);
}
