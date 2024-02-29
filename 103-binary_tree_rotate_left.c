#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    if (tree == NULL || tree->right == NULL)
        return tree;

    binary_tree_t *new_root = tree->right;
    binary_tree_t *temp = new_root->left;

    /* Perform rotation */
    new_root->left = tree;
    tree->parent = new_root;
    tree->right = temp;

    if (temp != NULL)
        temp->parent = tree;

    new_root->parent = tree->parent;

    if (tree->parent != NULL)
    {
        if (tree->parent->left == tree)
            tree->parent->left = new_root;
        else
            tree->parent->right = new_root;
    }

    return new_root;
}

