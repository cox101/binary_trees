#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    if (tree == NULL || tree->left == NULL)
        return tree;

    binary_tree_t *root = tree->left;
    binary_tree_t *temp = root->right;

    /* Perform rotation */
    root->right = tree;
    tree->parent = root;
    tree->left = temp;

    if (temp != NULL)
        temp->parent = tree;

    root->parent = tree->parent;

    if (tree->parent != NULL)
    {
        if (tree->parent->left == tree)
            tree->parent->left = root;
        else
            tree->parent->right = root;
    }

    return root;
}

