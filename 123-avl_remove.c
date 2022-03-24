#include "binary_trees.h"

/**
 * bst_remove - Remove a node from BST tree
 *
 * @root: Pointer to the root node
 * @value: Value to remove
 *
 * Return: Pointer to the root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *parent, *successor;

	if (!root)
		return (root);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			root = NULL;
		}
		else if (root->left && root->right)
		{
			successor = root->right;
			while (successor->left)
				successor = successor->left;
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
		else if (!root->right || !root->left)
		{
			tmp = root;
			parent = root->parent;
			root = root->left ? root->left : root->right;
			root->parent = parent;
			free(tmp);
		}
	}
	return (root);
}

/**
 * rebalance - Rebalance the tree after the removed node
 *
 * @root: Pointer to the node to check if we need to rebalance
 *
 * Return: Anything, cause void function
 */
void rebalance(avl_t *root)
{
	avl_t *tmp = root;

	while (tmp)
	{
		if (binary_tree_balance(tmp) > 1 && binary_tree_balance(tmp->left) > 0)
		{
			if (root == tmp)
				root = tmp->left->right;
			binary_tree_rotate_left(tmp->left);
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) > 1 && binary_tree_balance(tmp->left) <= 0)
		{
			if (root == tmp)
				root = tmp->left;
			binary_tree_rotate_right(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 &&
				binary_tree_balance(tmp->right) > 0)
		{
			if (root == tmp)
				root = tmp->right->left;
			binary_tree_rotate_right(tmp->right);
			binary_tree_rotate_left(tmp);
		}
		else if (binary_tree_balance(tmp) < -1 &&
				binary_tree_balance(tmp->right) <= 0)
		{
			if (root == tmp)
				root = tmp->right;
			binary_tree_rotate_left(tmp);
		}

		tmp = tmp->parent;
	}
}

/**
 * bst_search - Search a value into the BST
 *
 * @tree: Pointer to the root node
 * @value: Value to search
 *
 * Return: Return pointer to the founded node
 */
avl_t *bst_search(const avl_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}

/**
* avl_remove - function that inserts a value in an AVL Tree
*
* @root: pointer to the root node of the tree for removing a node
* @value: value to remove in the tree
*
* Return:
*	pointer to the created tree
*	NULL if no rotation
*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *ancestor = NULL;

	if (!root)
		return (NULL);

	ancestor = bst_search(root, value);
	if (ancestor)
		ancestor = ancestor->parent;

	bst_remove(root, value);

	rebalance(ancestor);
	rebalance(root->right);
	rebalance(root->left);

	return (root);
}
