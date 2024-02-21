#include <stdio.h>
#include <stdlib.h>

struct node
{
    void *data;
    struct node *next;
};

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
