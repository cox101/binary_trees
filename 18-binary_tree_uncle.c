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

    /* Get the parent of the node */
    binary_tree_t *parent = node->parent;

    /* If the parent's parent is NULL, there's no uncle */
    if (parent->parent == NULL)
        return NULL;

    /* Get the uncle node by accessing the sibling of the parent */
    if (parent->parent->left == parent)
        return parent->parent->right;  /* Uncle is the right child of the grandparent */
    else
        return parent->parent->left;   /* Uncle is the left child of the grandparent */
}

