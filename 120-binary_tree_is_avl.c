#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value that a node in the tree can have
 * @max: The maximum value that a node in the tree can have
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n < min || tree->n > max)
        return 0;

    return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
            binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height of
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (tree == NULL)
        return 0;

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    return (1 + (height_left > height_right ? height_left : height_right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height_diff, is_bst;

    if (tree == NULL)
        return 0;

    is_bst = binary_tree_is_bst(tree, INT_MIN, INT_MAX);
    if (!is_bst)
        return 0;

    if (tree->left)
    {
        height_diff = binary_tree_height(tree->left) - binary_tree_height(tree->right);
        if (height_diff > 1 || height_diff < -1)
            return 0;
    }

    if (tree->right)
    {
        height_diff = binary_tree_height(tree->right) - binary_tree_height(tree->left);
        if (height_diff > 1 || height_diff < -1)
            return 0;
    }

    return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

