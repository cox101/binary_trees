#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_t *queue = NULL;
    const binary_tree_t *current;

    /* Enqueue the root node */
    enqueue(&queue, (void *)tree);

    while (queue != NULL)
    {
        /* Dequeue the front node and process it */
        current = (const binary_tree_t *)dequeue(&queue);
        func(current->n);

        /* Enqueue left child if exists */
        if (current->left != NULL)
            enqueue(&queue, (void *)current->left);

        /* Enqueue right child if exists */
        if (current->right != NULL)
            enqueue(&queue, (void *)current->right);
    }
}
