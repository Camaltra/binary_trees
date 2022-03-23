#include "binary_trees.h"


/**
* bst_remove - Remove a node from BST tree
*
* @root: Pointer to the root node
* @value: Value to remove
*
* Return: Pointer to the root node
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor;
	int tmp;

	if (!root)
		return (root);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (root->left && root->right)
		{
			successor = root->right;
			while (successor->left)
				successor = successor->left;
			tmp = successor->n;
			bst_remove(root, successor->n);
			root->n = tmp;
		}
		else
		{
			successor = root->left ? root->left : root->right;
			free(root);
			root = successor;
		}
	}
	return (root);
}
