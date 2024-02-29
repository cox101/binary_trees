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

    /* Create a queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1000);
    if (queue == NULL)
        return;

    int front = 0, rear = 0;
    queue[rear++] = (binary_tree_t *)tree;

    /* Perform level-order traversal */
    while (front < rear)
    {
        const binary_tree_t *current = queue[front++];
        func(current->n);

        if (current->left != NULL)
            queue[rear++] = (binary_tree_t *)current->left;
        if (current->right != NULL)
            queue[rear++] = (binary_tree_t *)current->right;
    }

    free(queue);
}

