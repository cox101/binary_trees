#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - Recursive utility function to check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum value allowed for nodes in the subtree.
 * @max: The maximum value allowed for nodes in the subtree.
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    /* Check if the current node's value violates the BST property */
    if (tree->n <= min || tree->n >= max)
        return 0;

    /* Check the left subtree (values should be less than the current node's value) */
    /* Check the right subtree (values should be greater than the current node's value) */
    return is_bst_util(tree->left, min, tree->n) && is_bst_util(tree->right, tree->n, max);
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

    /* Call the recursive utility function with initial minimum and maximum values */
    return is_bst_util(tree, INT_MIN, INT_MAX);
}

