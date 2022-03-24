#include "binary_trees.h"

/**
* sorted_array_to_avl - function that builds an AVL tree from an array
*
* @array: pointer to the first element of the array to be converted
* @size: number of element in the array
*
* Return:
*	pointer to the root node of the created AVL tree
*	NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *nodeLeft, *nodeRight, *node = NULL;
	size_t mid;

	if (size == 0 || !array)
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	mid = (size - 1) / 2;
	node->n = array[mid];
	node->parent = NULL;

	if (mid > 0)
		nodeLeft = sorted_array_to_avl(array, mid);
	else
		nodeLeft = NULL;

	if ((size - 1) > mid)
		nodeRight = sorted_array_to_avl(&array[mid + 1], size - (mid + 1));
	else
		nodeRight = NULL;

	node->left = nodeLeft;
	node->right = nodeRight;

	if (node->left)
		(node->left)->parent = node;

	if (node->right)
		(node->right)->parent = node;

	return (node);
}
