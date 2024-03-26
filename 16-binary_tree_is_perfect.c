#include "binary_trees.h"

const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, int depth, int level);
size_t binary_tree_depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect(tree, binary_tree_depth(get_leaf(tree)), 0));
}

/**
 * is_perfect - utility function to check if tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: computed depth of tree
 * @level: current level
 * Return: 1 if perfect, 0 if not
 */
int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (is_leaf(tree))
		return (level == depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree->parent != NULL)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}


/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_leaf - Checks if a node is a leaf node.
 * @node: Pointer to the node to check.
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
