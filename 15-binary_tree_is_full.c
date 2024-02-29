#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* If the current node has no children, it is a leaf (full) */
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    /* If the current node has exactly two children, check the left and right subtrees */
    if (tree->left != NULL && tree->right != NULL)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    /* If the current node has only one child, the tree is not full */
    return 0;
}

