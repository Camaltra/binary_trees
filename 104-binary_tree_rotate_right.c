#include "binary_trees.h"

/**
* binary_tree_rotate_right - Rotate the given tree on the right
*
* @tree: Pointer to the tree
*
* Return:
*	Pointer to the new root of the tree
*	NULL if no rotation
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || tree->left == NULL)
		return (NULL);

	pivot = tree->left;

	if (pivot->right)
		pivot->right->parent = tree;

	tree->left = pivot->right;
	pivot->right = tree;
	pivot->parent = NULL;
	tree->parent = pivot;

	return (pivot);
}
