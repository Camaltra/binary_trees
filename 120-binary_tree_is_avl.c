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
* binary_tree_is_bst - function that checks if a binary tree
*	is a valid Binary Search Tree
*
* @tree: pointer to the root node of the tree to check
*
* Return:
*	1 if tree is a valid BST
*	0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && tree->left->n > tree->n))
		return (0);
	if (tree->left && tree->parent && tree->parent->left == tree)
		if (tree->left->n > tree->parent->n)
			return (0);
	if (tree->left && tree->parent && tree->parent->right == tree)
		if (tree->left->n < tree->parent->n)
			return (0);

	if ((tree->right && tree->right->n < tree->n))
		return (0);
	if (tree->right && tree->parent && tree->parent->left == tree)
		if (tree->right->n > tree->parent->n)
			return (0);
	if (tree->right && tree->parent && tree->parent->right == tree)
		if (tree->right->n < tree->parent->n)
			return (0);

	return (binary_tree_is_bst(tree->left) * binary_tree_is_bst(tree->right));
}


/**
* binary_tree_is_avl - function that checks if a binary tree
*	is a valid AVL Tree
*
* @tree: ter to the root node of the tree to check
*
* Return:
*	1 if tree is a valid AVL Tree
*	0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (binary_tree_height(tree->left) - binary_tree_height(tree->right) < 2)
		return (binary_tree_is_bst(tree));

	return (0);
}
