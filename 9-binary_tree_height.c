#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftcount = 0, rightcount = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	leftcount = binary_tree_height(tree->left);
	rightcount = binary_tree_height(tree->right);
	if (leftcount > rightcount)
		return (leftcount + 1);
	return (rightcount + 1);
}
