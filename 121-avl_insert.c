#include "binary_trees.h"

/**
* avl_insert - function that inserts a value in an AVL Tree
*
* @tree: double pointer to the root node of the AVL tree
*	for inserting the value
* @value: value to store in the node to be inserted
*
* Return:
*	pointer to the created node
*	NULL if no rotation
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = avl_insert_node(*tree, value);

	if (!tree || (*tree) == NULL)
		*tree = newNode;

	if (newNode->parent && newNode->parent->parent)
	{
		if (binary_tree_balance(newNode->parent->parent) > 1)
		{
			if (newNode->n < newNode->parent->parent->n && newNode->n > newNode->parent->n)
			{
				printf("first right rotate\n");
				binary_tree_print(*tree);
				printf("\n\n");
				binary_tree_rotate_left(newNode->parent);
				printf("\n");
				binary_tree_print(*tree);
				printf("\n\n");
				binary_tree_rotate_right(newNode->parent);
				printf("mewnode de parent n %d\n", newNode->n);
				printf("\n");
				if (newNode->parent == NULL)
				{
					*tree = newNode;
					/*
					if (newNode->parent->parent->left == newNode->parent)
					{
						newNode->parent->parent->left = newNode->parent;
					}
					else
					{
						newNode->parent->parent->right = newNode->parent;
					}*/
				}
			}
			else
				binary_tree_rotate_left(newNode->parent->parent);
		}
		else if (binary_tree_balance(newNode->parent->parent) < -1)
		{
			if (newNode->n > newNode->parent->parent->n && newNode->n < newNode->parent->n)
			{
				printf("first left rotate\n");
				binary_tree_print(*tree);
				printf("\n\n");
				binary_tree_rotate_right(newNode->parent);
				binary_tree_print(*tree);
				printf("\n\n");
				binary_tree_rotate_left(newNode->parent);
				// binary_tree_rotate_left(newNode->parent);
				if (newNode->parent == NULL)
				{
					*tree = newNode;
					/*
					if (newNode->parent->parent->left == newNode->parent)
					{
						newNode->parent->parent->left = newNode->parent;
					}
					else
					{
						newNode->parent->parent->right = newNode->parent;
					}*/
				}
			}
			else
				binary_tree_rotate_right(newNode->parent->parent);
		}
	}

	binary_tree_print(*tree);
	printf("\n\n");

	return (newNode);
}


/**
* avl_insert_node - function that inserts a node in an AVL Tree
*
* @tree: double pointer to the root node of the AVL tree
*	for inserting the value
* @value: value to store in the node to be inserted
*
* Return:
*	pointer to the created node
*	NULL if fail
*/
avl_t *avl_insert_node(avl_t *tree, int value)
{
	if (!tree)
		return (binary_tree_node(NULL, value));

	if (value < tree->n && tree->left == NULL)
	{
		tree->left = binary_tree_node(tree, value);
		return (tree->left);
	}
	else if (value < tree->n && tree->left)
		return (avl_insert_node(tree->left, value));

	if (value > tree->n && tree->right == NULL)
	{
		tree->right = binary_tree_node(tree, value);
		return (tree->right);
	}
	else if (value > tree->n && tree->right)
		return (avl_insert_node(tree->right, value));

	return (NULL);
}
