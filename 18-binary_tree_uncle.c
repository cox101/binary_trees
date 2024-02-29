#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node in a binary tree
 * @node: pointer to the node to find the uncle of
 *
 * Return: pointer to the uncle node, or NULL if no uncle or if node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    /* Determine if the parent is the left child or the right child of the grandparent */
    if (node->parent == node->parent->parent->left)
        return node->parent->parent->right; /* Return the right child (uncle) of the grandparent */
    else
        return node->parent->parent->left;  /* Return the left child (uncle) of the grandparent */
}
