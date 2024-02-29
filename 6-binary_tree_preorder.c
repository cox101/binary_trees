#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: Pre-order traversal visits the current node, then its left
 * child, and finally its right child.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
       	if (tree == NULL || func == NULL)
	    return;
    
    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}

