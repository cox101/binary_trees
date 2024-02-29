#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * print_level - prints nodes at a given level
 * @node: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 * @level: level to print
 */
void print_level(const binary_tree_t *node, void (*func)(int), int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        func(node->n);
    else if (level > 1)
    {
        print_level(node->left, func, level - 1);
        print_level(node->right, func, level - 1);
    }
}

/**
 * binary_tree_levelorder - performs level-order traversal of a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t height, level;

    if (tree == NULL || func == NULL)
        return;

    height = binary_tree_height(tree);

    for (level = 1; level <= height; level++)
        print_level(tree, func, level);
}

