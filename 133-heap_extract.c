#include "binary_trees.h"

/**
* binary_tree_size_bis - Count the size of a binary tree
*
* @tree: Pointer to the binary tree
*
* Return: The size of the binary tree
*/
size_t binary_tree_size_bis(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size_bis(tree->left) +
			binary_tree_size_bis(tree->right) + 1);
}

/**
* getNodeFromIndexBis - Get a node form it's index of the heap
*
* @root: Pointer to the root node
* @idx: Index of a the node to search
*
* Return: Pointer to the node
*/
heap_t *getNodeFromIndexBis(heap_t *root, int idx)
{
	int parentIdx, direction;

	if (idx == 0)
		return (root);

	parentIdx = (idx - 1) / 2;
	direction = (idx - 1) % 2;

	if (direction == 0)
		return (getNodeFromIndexBis(root, parentIdx)->left);
	return (getNodeFromIndexBis(root, parentIdx)->right);
}

/**
* swap - Swap two node value
*
* @nodeOne: First node
* @nodeTwo: Second node
*
* Return: Anything, cause void function
*/
void swap(heap_t *nodeOne, heap_t *nodeTwo)
{
	int tmp;

	tmp = nodeOne->n;
	nodeOne->n = nodeTwo->n;
	nodeTwo->n = tmp;
}

/**
* reHepify - Re hepify a heap
*
* @root: Pointer to the root node
*
* Return: Anything, cause void function
*/
void reHepify(heap_t *root)
{
	heap_t *largest = root;

	if (!root || (!root->left && !root->right))
		return;

	if (root->left && largest->n < root->left->n)
		largest = root->left;
	if (root->right && largest->n < root->right->n)
		largest = root->right;

	if (largest != root)
	{
		swap(root, largest);
		reHepify(largest);
	}
}

/**
* heap_extract - Extrat the root node from the tree
*
* @root: Double pointer of the root
*
* Return: The value of the of the root, 0 if not exist
*/
int heap_extract(heap_t **root)
{
	heap_t *tmpNode = NULL;
	int lastNodeIdx, tmp, reValue = 0;

	if (!root || !*root)
		return (0);

	lastNodeIdx = binary_tree_size_bis(*root) - 1;
	if (lastNodeIdx == 0)
	{
		reValue = (*root)->n;
		free(*root);
		*root = NULL;
		return (reValue);
	}
	tmpNode = getNodeFromIndexBis(*root, lastNodeIdx);

	tmp = tmpNode->n;
	tmpNode->n = (*root)->n;
	(*root)->n = tmp;
	reValue = tmpNode->n;

	if (tmpNode->parent->left == tmpNode)
		tmpNode->parent->left = NULL;
	else
		tmpNode->parent->right = NULL;

	free(tmpNode);
	reHepify(*root);
	return (reValue);
}
