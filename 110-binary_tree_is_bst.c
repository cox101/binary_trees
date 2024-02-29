#include "binary_trees.h"

/**
 * is_bst_util - Utility function to check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value allowed for nodes in this subtree (inclusive).
 * @max: The maximum value allowed for nodes in this subtree (inclusive).
 *
 * Return: 1 if the subtree is a valid BST, otherwise 0.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    /* Check if the node's value violates the BST property */
    if (tree->n <= min || tree->n >= max)
        return 0;

    /* Recursively check the left and right subtrees */
    return (is_bst_util(tree->left, min, tree->n) &&
            is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Call the utility function with appropriate initial min and max values */
    return is_bst_util(tree, INT_MIN, INT_MAX);
}

