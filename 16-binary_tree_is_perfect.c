#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, i;
    size_t nodes_expected, nodes_count = 0;

    if (tree == NULL)
        return 0;

    height = binary_tree_height(tree);

    /* Calculate the number of nodes expected in a perfect binary tree */
    nodes_expected = 1;
    for (i = 0; i < height; i++)
        nodes_expected *= 2;

    /* Count the number of nodes in the tree */
    nodes_count = binary_tree_size(tree);

    /* Check if the number of nodes matches the expected number for a perfect binary tree */
    return (nodes_count == nodes_expected);
}

