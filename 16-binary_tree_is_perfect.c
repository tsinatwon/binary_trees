#include "binary_trees.h"

/**
  * _binary_tree_height - helper function for binary_tree_height
  * @tree: input tree
  *
  * Return: height of tree
  */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);

	a = _binary_tree_height(tree->left);
	b = _binary_tree_height(tree->right);
	return (MAX(a, b) + 1);
}

/**
  * binary_tree_height - measures height of a binary tree
  * @tree: input tree
  *
  * Return: height of tree.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_height(tree) - 1);
}


/**
  * binary_tree_size - measures size of a binary tree.
  * @tree: input binary tree.
  *
  * Return: number of descedant child nodes.
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: iput binary tree
  *
  * Return: 1 if true, 0 if false
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int i, j;

	if (!tree)
		return (0);
	i = (int)binary_tree_size(tree);
	j = binary_tree_height(tree);
	return (i == (2 << j) - 1);
}
