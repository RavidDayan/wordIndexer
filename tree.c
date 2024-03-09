#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "tree.h"

struct node *insert(struct node *tree, char *newToken, int line)
{
    int compare;
    if (tree == NULL) /*if reached a leaf make a new node and set it there*/
    {
        tree = newNode(newToken);
        setLine(tree, line);
    }
    else
    {
        compare = strcmp(newToken, tree->token);
        if (compare == 0)
        {
            setLine(tree, line);
        }
        else if (compare > 0)
        {
            tree->right = insert(tree->right, newToken, line);
        }
        else
        {
            tree->left = insert(tree->left, newToken, line);
        }
    }
    return tree;
}
void maxToMinFunc(struct node *tree)
{
    int *lines;
    if (tree != NULL)
    {
        maxToMinFunc(tree->left);
        /*printing of a node as asked*/
        printf("%s", tree->token);
        lines = tree->lines;
        if (lines[1] != 0 && lines[1] != LINE_SENTRY)
        {
            printf(" appears in lines ");
        }
        else
        {
            printf(" appears in line ");
        }
        while (*lines != LINE_SENTRY && *lines != 0)
        {
            printf(" %d", *lines);
            lines++;
        }
        printf("\n");
        maxToMinFunc(tree->right);
    }
}
void freeTree(struct node *tree)
{
    if (tree != NULL)
    {

        freeTree(tree->left);
        freeTree(tree->right);
        freeNode(tree);
    }
}