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
* binary_tree_is_bst - Check if a binary tree is a
*               binary search tree.
*
* @tree: The tree to check
*
* Return: 0 if not, 1 else
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_bst_rec(tree, INT_MIN, INT_MAX));
}
