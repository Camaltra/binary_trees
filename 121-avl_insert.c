#include "binary_trees.h"

/**
* avl_insert - function that inserts a value in an AVL Tree
*
* @tree: double pointer to the root node of the AVL tree
*	for inserting the value
* @value: value to store in the node to be inserted
*
* Return:
*	pointer to the created tree
*	NULL if no rotation
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = bst_insert(tree, value);
	avl_t *tmp = newNode;

	if (!tree || *tree == NULL)
		*tree = newNode;

	while (tmp)
	{
		if (binary_tree_balance(tmp) > 1 && tmp->left->n < value)
		{
			if (*tree == tmp)
				*tree = tmp->left->right;
			binary_tree_rotate_left(tmp->left);
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) > 1 && tmp->left->n > value)
		{
			if (*tree == tmp)
				*tree = tmp->left;
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 && tmp->right->n > value)
		{
			if (*tree == tmp)
				*tree = tmp->right->left;
			binary_tree_rotate_right(tmp->right);
			binary_tree_rotate_left(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 && tmp->right->n < value)
		{
			if (*tree == tmp)
				*tree = tmp->right;
			tmp = binary_tree_rotate_left(tmp);
		}

		tmp = tmp->parent;
	}

	return (newNode);
}


/**
* bst_insert - Insert a node into a bst tree
*
* @tree: Double pointer to the tree
* @value: The value to insert into the tree
*
* Return: Pointer to the new created node
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *browse = NULL;

	if (!*tree)
	{
		*tree = (binary_tree_node(NULL, value));
		return (*tree);
	}

	browse = *tree;
	while (browse)
	{
		if (value == browse->n)
			return (NULL);
		else if (value > browse->n)
		{
			if (browse->right == NULL)
			{
				browse->right = binary_tree_node(browse, value);
				return (browse->right);
			}

			browse = browse->right;
		}
		else if (value < browse->n)
		{
			if (browse->left == NULL)
			{
				browse->left = binary_tree_node(browse, value);
				return (browse->left);
			}

			browse = browse->left;
		}
	}

	return (NULL);
}
