#include "binary_trees.h"

/**
* avl_remove - function that inserts a value in an AVL Tree
*
* @tree: pointer to the root node of the tree for removing a node
* @value: value to remove in the tree
*
* Return:
*	pointer to the created tree
*	NULL if no rotation
*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp, *parent, *successor, *tmpBalance;

	if (!root)
		return (root);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (root->left && root->right)
		{
			successor = root->right;
			while (successor->left)
				successor = successor->left;
			root->n = successor->n;
			tmpBalance = root;
			while (tmpBalance->parent)
				tmpBalance = tmpBalance->parent;
			rebalance(&tmpBalance);
		}
		else if (!root->right || !root->left)
		{
			tmp = root;
			parent = root->parent;
			root = root->left ? root->left : root->right;
			root->parent = parent;
			free (tmp);
		}
	}

	return (root);
}


void rebalance(avl_t **root)
{
	avl_t *tmp = *root;

	if ((*root)->left)
		rebalance(&(*root)->left);
	if ((*root)->right)
		rebalance(&(*root)->right);
	
	while (tmp)
	{
		if (binary_tree_balance(tmp) > 1 && tmp->left->n < tmp->n)
		{
			if (*root == tmp)
				*root = tmp->left->right;
			binary_tree_rotate_left(tmp->left);
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) > 1 && tmp->left->n > tmp->n)
		{
			if (*root == tmp)
				*root = tmp->left;
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 && tmp->right->n > tmp->n)
		{
			if (*root == tmp)
				*root = tmp->right->left;
			binary_tree_rotate_right(tmp->right);
			binary_tree_rotate_left(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 && tmp->right->n < tmp->n)
		{
			if (*root == tmp)
				*root = tmp->right;
			tmp = binary_tree_rotate_left(tmp);
		}

		tmp = tmp->parent;
	}
}