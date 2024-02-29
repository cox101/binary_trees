#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height of
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (tree == NULL)
        return 0;

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    return (1 + (height_left > height_right ? height_left : height_right));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor of
 *
 * Return: The balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * avl_rotate_left - Performs a left-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node after rotation
 */
avl_t *avl_rotate_left(avl_t *tree)
{
    avl_t *new_root = tree->right;

    tree->right = new_root->left;
    if (new_root->left != NULL)
        new_root->left->parent = tree;
    new_root->left = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return new_root;
}

/**
 * avl_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 *
 * Return: A pointer to the new root node after rotation
 */
avl_t *avl_rotate_right(avl_t *tree)
{
    avl_t *new_root = tree->left;

    tree->left = new_root->right;
    if (new_root->right != NULL)
        new_root->right->parent = tree;
    new_root->right = tree;
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return new_root;
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree for inserting the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node, *current, *parent;
    int balance;

    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    current = *tree;
    parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (value == current->n)
            return NULL;

        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return NULL;

    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    current = new_node;
    while (current != NULL)
    {
        balance = binary_tree_balance(current);
        if (balance > 1)
        {
            if (value < current->left->n)
                current = avl_rotate_right(current);
            else
            {
                current->left = avl_rotate_left(current->left);
                current = avl_rotate_right(current);
            }
        }
        else if (balance < -1)
        {
            if (value > current->right->n)
                current = avl_rotate_left(current);
            else
            {
                current->right = avl_rotate_right(current->right);
                current = avl_rotate_left(current);
            }
        }

        if (current->parent == NULL)
            *tree = current;

        current = current->parent;
    }

    return new_node;
}

