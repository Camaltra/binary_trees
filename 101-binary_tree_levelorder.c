#include "binary_trees.h"

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
	if (tree == NULL)
		return;

	if (!tree->parent)
		func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
