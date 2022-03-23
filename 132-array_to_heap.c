#include "binary_trees.h"

/**
* array_to_heap - Create a heap from an array
*
* @array: Pointer to the array
* @size: Size of the array
*
* Return: Pointer to the root node
*/
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (size == 0 || !array)
		return (NULL);

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
