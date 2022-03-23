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
* getNodeFromIndex - Get a node form it's index of the heap
*
* @root: Pointer to the root node
* @idx: Index of a the node to search
*
* Return: Pointer to the node
*/
heap_t *getNodeFromIndex(heap_t *root, int idx)
{
	int parentIdx, direction;

	if (idx == 0)
		return (root);

	parentIdx = (idx - 1) / 2;
	direction = (idx - 1) % 2;

	if (direction == 0)
		return (getNodeFromIndex(root, parentIdx)->left);
	return (getNodeFromIndex(root, parentIdx)->right);
}

/**
* heap_insert - Insert a node into an heap
*
* @root: Double pointer to the root node
* @value: Value to insert
*
* Return: Pointer to the created node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent = NULL, *new = NULL;
	int idxParent, tmp, size;

	new = binary_tree_node(NULL, value);

	if (!*root)
	{
		*root = new;
		return (*root);
	}

	size = binary_tree_size(*root);
	idxParent = (size - 1) / 2;
	parent = getNodeFromIndex(*root, idxParent);
	new->parent = parent;
	if (size % 2 == 0)
		parent->right = new;
	else
		parent->left = new;

	while (parent && parent->n < new->n)
	{
		tmp = parent->n;
		parent->n = new->n;
		new->n = tmp;
		new = parent;
		parent = new->parent;
	}
	return (new);
}
