#include "binary_trees.h"

/**
* binary_tree_insert_right - Add a node to the right, from a parent
*						If right node already exist, push it down
*						into the tree
*
* @parent: The parent node
* @value: The value to fill
*
* Return: Pointer to the created node.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);

	if (parent->right == NULL)
		parent->right = newNode;
	else
	{
		newNode->right = parent->right;
		parent->right->parent = newNode;
		parent->right = newNode;
	}
	return (newNode);
}
