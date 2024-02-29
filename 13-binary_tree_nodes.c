#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least one child in a binary tree
 * @tree: pointer to the root node of the tree to count nodes
 *
 * Return: number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* If the current node has at least one child, return 1 */
    if (tree->left != NULL || tree->right != NULL)
        return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

    /* If the current node is a leaf, return 0 */
    return 0;
}

