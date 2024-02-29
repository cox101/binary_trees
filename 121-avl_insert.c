#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return NULL;
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&(*tree)->left, value);
        if ((*tree)->left == NULL)
            return NULL;
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&(*tree)->right, value);
        if ((*tree)->right == NULL)
            return NULL;
    }
    else
    {
        /* Value already exists, return NULL */
        return NULL;
    }

    /* Update height and balance factor */
    (*tree)->height = 1 + MAX(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));
    (*tree)->bf = binary_tree_balance(*tree);

    /* Perform rotations if necessary */
    if ((*tree)->bf > 1)
    {
        if (value < (*tree)->left->n)
            *tree = binary_tree_rotate_right(*tree);
        else
        {
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            *tree = binary_tree_rotate_right(*tree);
        }
    }
    else if ((*tree)->bf < -1)
    {
        if (value > (*tree)->right->n)
            *tree = binary_tree_rotate_left(*tree);
        else
        {
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            *tree = binary_tree_rotate_left(*tree);
        }
    }

    return *tree;
}

