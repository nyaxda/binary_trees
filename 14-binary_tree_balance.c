#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height_helper(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		if (tree->left != NULL)
			left_height = 1 + binary_tree_height_helper(tree->left);
		else
			left_height = 1;

		if (tree->right != NULL)
			right_height = 1 + binary_tree_height_helper(tree->right);
		else
			right_height = 1;

		if (left_height > right_height)
			return (left_height);
		else
			return (right_height);
	}
	return 0;
}
size_t binary_tree_height_helper(const binary_tree_t *tree);

/**
 * binary_tree_balance - function that measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height_helper(tree->left) - binary_tree_height_helper(tree->right));
	return (0);
}
