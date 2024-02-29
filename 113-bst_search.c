#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing a value equals to `value`.
 *         If `tree` is NULL or if nothing is found, return NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    /* Base cases: If tree is NULL or if value is found */
    if (tree == NULL || tree->n == value)
        return (bst_t *)tree;

    /* If value is less than the current node's value, search in left subtree */
    if (value < tree->n)
        return bst_search(tree->left, value);
    
    /* If value is greater than the current node's value, search in right subtree */
    return bst_search(tree->right, value);
}

