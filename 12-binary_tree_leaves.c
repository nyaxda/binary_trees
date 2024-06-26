#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t total_leaves, left_total_leaves = 0, right_total_leaves = 0;

	if (tree == NULL)
		return (0);
	left_total_leaves = binary_tree_leaves(tree->left);
	right_total_leaves = binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	total_leaves = left_total_leaves + right_total_leaves;
	return (total_leaves);
}
