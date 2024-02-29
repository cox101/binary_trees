#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL)
	    return NULL;
    binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
	    return NULL;
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    if (parent->right == NULL)
    {
	    parent->right = node;
    }
    else
    {
	    node->right = parent->right;
	    parent->right->parent = node;
	    parent->right = node;
    }
    return node;
}
