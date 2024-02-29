#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    /* If either first or second is one of the nodes, return it */
    if (first == second)
        return (binary_tree_t *)first;

    /* Search for the LCA recursively */
    binary_tree_t *left_lca = binary_trees_ancestor(first->left, second);
    binary_tree_t *right_lca = binary_trees_ancestor(first->right, second);

    /* If both left and right LCA are non-null, the current node is the LCA */
    if (left_lca != NULL && right_lca != NULL)
        return (binary_tree_t *)first;

    /* If one of the subtrees contains one of the nodes, return the LCA from that subtree */
    if (left_lca != NULL)
        return left_lca;
    if (right_lca != NULL)
        return right_lca;

    /* If neither of the subtrees contains any of the nodes, return NULL */
    return NULL;
}

