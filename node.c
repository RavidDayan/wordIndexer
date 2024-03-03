#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

struct node *newNode(char *name)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    newNode->name = (char *)calloc(strlen(name) / sizeof(char), sizeof(char));
    newNode->lines = (int *)calloc(LINE_BUFFER, sizeof(int));
    newNode->lines[LINE_BUFFER - 1] = LINE_SENTRY;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void setNext(struct node *this, struct node *next)
{
    this->next = next;
}
void setLine(struct node *this, int line)
{
    int i;
    for (i = 0; this->lines[i] != LINE_SENTRY; i++)
    {
        if (this->lines[i] == 0)
        {
            this->lines[i] = line;
            return;
        }
    }
    if (this->lines[i] == LINE_SENTRY)
    {
        this->lines = realloc(this->lines, (strlen(this->lines) / sizeof(int)) + LINE_BUFFER);
        if (this->lines == NULL)
        {
            perror("Error reallocating memory");
        }
        else
        {
            this->lines[(strlen(this->lines) / sizeof(int)) - 1] = LINE_SENTRY;
            this->lines[i] = line;
        }
    }
}
struct node *getNext(struct node *this)
{
    return this->next;
}
char *getName(struct node *this)
{
    return this->name;
}
int *getLines(struct node *this)
{
    return this->lines;
}
void freeNode(struct node *this)
{
    free(this->name);
    free(this->lines);
    free(this);
}
int compareNode(struct node *this, struct node *other)
{
    int i = 0;
    char *first = this->name;
    char *second = other->name;
    while (first[i] != '\0' && second[i] != '\0')
    {
        if (first[i] < second[i])
        {
            return BIGGER;
        }
        if (first[i] > second[i])
        {
            return SMALLER;
        }
    }
    if (first[i] != '\0' && second[i] == '\0')
    {
        return BIGGER;
    }
    if (first[i] == '\0' && second[i] != '\0')
    {
        return SMALLER;
    }
    return EQUAL;
}