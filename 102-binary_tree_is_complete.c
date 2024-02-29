#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Create a queue for level order traversal */
    queue_t *queue = NULL;

    /* Enqueue the root node */
    enqueue(&queue, (void *)tree);

    /* Flag to indicate if we have encountered a NULL node */
    int null_encountered = 0;

    /* Perform level order traversal */
    while (queue != NULL)
    {
        /* Dequeue front node */
        const binary_tree_t *current = (const binary_tree_t *)dequeue(&queue);

        /* If a NULL node is encountered after a non-NULL node, return 0 */
        if (current == NULL)
        {
            null_encountered = 1;
            continue;
        }

        /* If a NULL node is encountered before a non-NULL node, return 0 */
        if (null_encountered && current != NULL)
            return (0);

        /* Enqueue left child */
        enqueue(&queue, (void *)current->left);

        /* Enqueue right child */
        enqueue(&queue, (void *)current->right);
    }

    /* If we have completed the traversal without returning 0, return 1 */
    return (1);
}

