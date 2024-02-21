#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node *newNode(void *data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
