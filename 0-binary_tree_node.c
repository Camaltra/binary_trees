#include "binary_trees.h"

/**
* binary_tree_node - Create a node of binary tree struct,
*                      If no parent are given, create the parent
*
* @parent: The parent node
* @value: The value to fill
*
* Return: Pointer to the created node.
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;

	return (newNode);
}
