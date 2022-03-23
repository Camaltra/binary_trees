#include "binary_trees.h"

/**
* binary_tree_rotate_left - Rotate the given tree on the left
*
* @tree: Pointer to the tree
*
* Return: Pointer to the new root of the tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *leftNode;

	if (!tree || !tree->left)
		return (NULL);

	leftNode = tree->left;
	tree->left = leftNode->right;
	if (tree->left)
		tree->left->parent = tree;
	leftNode->right = tree;
	leftNode->parent = tree->parent;
	tree->parent = leftNode;
	if (leftNode->parent)
	{
		if (leftNode->parent->left == tree)
			leftNode->parent->left = leftNode;
		else
			leftNode->parent->right = leftNode;
	}
	return (leftNode);
}


