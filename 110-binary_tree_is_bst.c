#include "binary_trees.h"

/* don't push this task */

/**
* binary_tree_is_bst - function that checks if a binary tree
*	is a valid Binary Search Tree
*
* @tree: ter to the root node of the tree to check
*
* Return:
*	1 if tree is a valid BST
*	0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && tree->left->n > tree->n) ||
		(tree->left && tree->parent && tree->parent->left == tree && tree->left->n > tree->parent->n) ||
		(tree->left && tree->parent && tree->parent->right == tree && tree->left->n < tree->parent->n))
			return (0);

	if ((tree->right && tree->right->n < tree->n) ||
		(tree->right && tree->parent && tree->parent->left == tree && tree->right->n > tree->parent->n) ||
		(tree->right && tree->parent && tree->parent->right == tree && tree->right->n < tree->parent->n))
			return (0);

	return (binary_tree_is_bst(tree->left) * binary_tree_is_bst(tree->right));
}
