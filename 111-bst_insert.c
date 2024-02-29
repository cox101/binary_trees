#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to insert into the BST.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    /* If tree is empty, create a new node and make it the root */
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    /* If value is less than current node's value, insert into left subtree */
    if (value < (*tree)->n)
    {
        /* Recursive call to insert into left subtree */
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            return (*tree)->left;
        }
        else
        {
            return bst_insert(&((*tree)->left), value);
        }
    }
    /* If value is greater than current node's value, insert into right subtree */
    else if (value > (*tree)->n)
    {
        /* Recursive call to insert into right subtree */
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            return (*tree)->right;
        }
        else
        {
            return bst_insert(&((*tree)->right), value);
        }
    }
    /* If value is equal to current node's value, ignore (duplicate value) */
    else
    {
        return NULL;
    }
}

