#include "binary_trees.h"

/**
* binary_tree_postorder - Print the binary tree in the postorder
*
* @tree: Pointer to the tree
* @func: Func to use
*
* Return: Anything, cause void function
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func == NULL)
		return;
	if (tree == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);

	func(tree->n);
}
