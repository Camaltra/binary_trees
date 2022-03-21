#include "binary_trees.h"

/**
* binary_tree_insert_left - Add a node to the left, from a parent
*						If left node already exist, push it down
*						into the tree
*
* @parent: The parent node
* @value: The value to fill
*
* Return: Pointer to the created node.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);

	if (parent->left == NULL)
		parent->left = newNode;
	else
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
		parent->left = newNode;
	}
	return (newNode);
}
