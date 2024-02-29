#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: pointer to the node to find the sibling of
 *
 * Return: pointer to the sibling node, or NULL if no sibling or if node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return NULL;

    /* If node is the left child, return the right child of the parent */
    if (node->parent->left == node)
        return node->parent->right;

    /* If node is the right child, return the left child of the parent */
    if (node->parent->right == node)
        return node->parent->left;

    return NULL;  /* No sibling found */
}

