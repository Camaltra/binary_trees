#include "binary_trees.h"

/**
* binary_tree_preorder - function that goes through a binary tree
*	using pre-order traversal
*
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
*
* Return:
*	None
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *nodeLeft, *nodeRight;

	if (tree == NULL || !func)
		return;

	nodeLeft = tree->left;
	nodeRight = tree->right;

	func(tree->n);

	binary_tree_preorder(nodeLeft, func);
	binary_tree_preorder(nodeRight, func);
}
