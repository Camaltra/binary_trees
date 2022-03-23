#include "binary_trees.h"

/**
* binary_tree_size - Count the size of a binary tree
*
* @tree: Pointer to the binary tree
*
* Return: The size of the binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}


/**
* binary_tree_is_complete_recursion - checks if a binary tree is complete
*
* @tree: Pointer to the binary tree
* @idx: index of the node
* @nbNode: number of node in tree
*
* Return:
*	1 if the binary tree is complete
*	0 otherwise
*/
int binary_tree_is_complete_recursion(const binary_tree_t *tree, int idx,
								int nbNode)
{
	if (!tree)
		return (1);

	if (idx >= nbNode)
		return (0);

	return (binary_tree_is_complete_recursion(tree->left, 2 * idx + 1, nbNode)
		* binary_tree_is_complete_recursion(tree->right, 2 * idx + 2, nbNode));
}


/**
* binary_tree_is_complete - function that checks if a binary tree is complete
*
* @tree: pointer to the root node of the tree to check
*
* Return:
*	1 if the binary tree is complete
*	0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nbNode = binary_tree_size(tree);

	return (binary_tree_is_complete_recursion(tree, 0, nbNode));
}

/**
* binary_tree_is_heap_rec - Help to the main function to create recursion
*
* @tree: Pointer to the tree node
* @max: Max value of the heap
*
* Return: 1 if it is a heap, 0 else
*/
int binary_tree_is_heap_rec(const binary_tree_t *tree, int max)
{
	if (!tree)
		return (1);
	if (tree->n > max || !binary_tree_is_complete(tree))
		return (0);
	return (binary_tree_is_heap_rec(tree->left, tree->n) &&
		binary_tree_is_heap_rec(tree->right, tree->n));
}

/**
* binary_tree_is_heap - Check if a binary tree is a heap
*
* @tree: Pointer to the tree
*
* Return: 1 if it is a heap, 0 else
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_heap_rec(tree, tree->n));
}
