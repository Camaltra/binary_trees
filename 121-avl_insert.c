#include "binary_trees.h"

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

/**
* avl_insert - Insert a node into an AVL tree
*
* 
*
*
*/
avl_t *avl_insert(avl_t **tree, int value)
{
    int balance = 0;
    avl_t *newNode = NULL;

    if (!tree)
        return (NULL);

    newNode = bst_insert(tree, value);
    balance = binary_tree_balance(*tree);
    if (balance > 1 && value < newNode->left->n)
        return binary_tree_rotate_right(newNode);
    if (balance < -1 && value > newNode->right->n)
        return binary_tree_rotate_left(newNode);
    if (balance > 1 && value > newNode->left->n)
    {
        newNode->left = binary_tree_rotate_left(newNode->left);
        return binary_tree_rotate_right(newNode);
    }
    if (balance < -1 && value < newNode->right->n)
    {
        newNode->right = binary_tree_rotate_right(newNode->right);
        return binary_tree_rotate_left(newNode);
    }
    return (newNode);
}