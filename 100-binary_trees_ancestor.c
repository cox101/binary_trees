#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    /* Check if either first or second is the current node */
    if (first == second)
        return (binary_tree_t *)first;

    /* Check if either first or second is a descendant of the current node */
    if (first == second->parent)
        return (binary_tree_t *)first;
    if (second == first->parent)
        return (binary_tree_t *)second;

    /* Recursively search for the lowest common ancestor in the left and right subtrees */
    binary_tree_t *left_ancestor = binary_trees_ancestor(first->parent, second);
    binary_tree_t *right_ancestor = binary_trees_ancestor(first, second->parent);

    /* If both left and right subtrees return non-NULL values, the current node is the LCA */
    if (left_ancestor != NULL && right_ancestor != NULL)
        return (binary_tree_t *)first;

    /* If only one subtree returns a non-NULL value, propagate it upwards */
    if (left_ancestor != NULL)
        return left_ancestor;
    if (right_ancestor != NULL)
        return right_ancestor;

    /* If both subtrees return NULL, return NULL */
    return NULL;
}

