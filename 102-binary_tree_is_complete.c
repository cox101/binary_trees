#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_complete_recursive(tree, 0, binary_tree_count_nodes(tree)));
}

/**
 * binary_tree_is_complete_recursive - recursively checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: index of the current node (starting from 0)
 * @node_count: total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree, size_t index, size_t node_count)
{
    if (tree == NULL)
        return (1);

    /* If current index exceeds the number of nodes, tree is not complete */
    if (index >= node_count)
        return (0);

    /* Recursively check left and right subtrees */
    return (binary_tree_is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
            binary_tree_is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_count_nodes - counts the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (1 + binary_tree_count_nodes(tree->left) + binary_tree_count_nodes(tree->right));
}

