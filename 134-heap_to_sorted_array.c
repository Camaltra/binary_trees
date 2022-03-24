#include "binary_trees.h"

/**
* binary_tree_size_bis2 - Count the size of a binary tree
*
* @tree: Pointer to the binary tree
*
* Return: The size of the binary tree
*/
size_t binary_tree_size_bis2(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size_bis2(tree->left) +
			binary_tree_size_bis2(tree->right) + 1);
}

/**
* heap_to_sorted_array - Transform an heap into a sorted array
*
* @heap: Pointer to the root heap
* @size: Pointer to the size of the array
*
* Return: The array that represent the heap, if not heap, return NULL
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i;
	int *stored = NULL;

	if (!heap)
		return (NULL);

	*size = binary_tree_size_bis2(heap);
	stored = malloc(sizeof(int) * (*size));
	if (!stored)
		return (NULL);
	for (i = 0; i < (*size); i++)
	{
		stored[i] = heap_extract(&heap);
	}
	return (stored);
}
