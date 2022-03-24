#include "binary_trees.h"
#include <limits.h>

/**
* binary_tree_is_bst_rec - Check if a tree is a bst, by using
*                       recusion function, help of the main function
*
* @tree: Tree to check
* @min: Min value of the tree
* @max: Max value of the tree
*
* Return: 0 if not, 1 else
*/
int binary_tree_is_bst_rec(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_tree_is_bst_rec(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst_rec(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_avl_rec - function that checks if a binary tree
*    is a valid AVL Tree recursively
*
* @tree: ter to the root node of the tree to check
*
* Return:
*    1 if tree is a valid AVL Tree
*    0 otherwise
*/
int binary_tree_is_avl_rec(const avl_t *tree)
{
	if (!tree)
		return (1);

	if (binary_tree_balance(tree) > 1 || binary_tree_balance(tree) < -1)
		return (0);

	return (binary_tree_is_avl_rec(tree->left) &&
			binary_tree_is_avl_rec(tree->right));

}

/**
* binary_tree_is_avl - function that checks if a binary tree
*    is a valid AVL Tree
*
* @tree: ter to the root node of the tree to check
*
* Return:
*    1 if tree is a valid AVL Tree
*    0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!binary_tree_is_bst_rec(tree, INT_MIN, INT_MAX))
		return (0);

	return (binary_tree_is_avl_rec(tree));
}

/**
* binary_tree_height - function that measures the height of a binary tree
*
* @tree: pointer to the root node of the tree to measure the height
*
* Return:
*    height of the tree
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
*    balance factor of the binary tree
*   0 if tree == NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
