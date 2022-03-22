#include "binary_trees.h"

/**
* binary_tree_rotate_left - Rotate the given tree on the left
*
* @tree: Pointer to the tree
*
* Return: Pointer to the new root of the tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rightNode;

	if (!tree || !tree->right)
		return (NULL);

	rightNode = tree->right;
	tree->right = rightNode->left;
	if (tree->right)
		tree->right->parent = tree;
	rightNode->left = tree;
	rightNode->parent = tree->parent;
	tree->parent = rightNode;
	if (rightNode->parent)
	{
		if (rightNode->parent->left == tree)
			rightNode->parent->left = rightNode;
		else
			rightNode->parent->right = rightNode;
	}
	return (rightNode);
}
