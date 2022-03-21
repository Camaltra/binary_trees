#include "binary_trees.h"

/**
* binary_tree_delete - function that deletes an entire binary tree
*
* @tree: The binary tree to delete
*
* Return: None
*/
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *nodeLeft, *nodeRight;

	if (tree == NULL)
		return;

	nodeLeft = tree->left;
	nodeRight = tree->right;

	binary_tree_delete(nodeLeft);
	binary_tree_delete(nodeRight);

	free(tree);
}
