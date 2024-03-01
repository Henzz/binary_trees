#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_count - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes in the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	size_t left_count;
	size_t right_count;

	if (tree == NULL)
		return (0);

	left_count = binary_tree_count(tree->left);
	right_count = binary_tree_count(tree->right);

	return (left_count + right_count + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t node_count;
	size_t max_node_count;
	size_t level;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	node_count = binary_tree_count(tree);

	max_node_count = 1;
	for (level = 0; level < height; level++)
	{
		max_node_count *= 2;
	}
	max_node_count--;

	return (node_count == max_node_count);
}
