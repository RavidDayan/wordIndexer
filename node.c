#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

struct node *newNode(char *token)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));/*alocate memory for struct*/
    if (newNode == NULL)/*check for successfull memory alocation*/
    {
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }
    newNode->token = (char *)malloc(strlen(token) * sizeof(char));/*initialize token memory base on string length*/
    if (newNode->token == NULL)/*check for successfull memory alocation*/
    {
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }
    newNode->token = token;
    newNode->lines = (int *)malloc(LINE_BUFFER * sizeof(int));/*initialize line memory based line_buffer*/
    if (newNode->lines == NULL)/*check for successfull memory alocation*/
    {
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }
    zeroArray(newNode->lines, LINE_BUFFER);/*zero cell represents an empty cell*/
    newNode->lines[LINE_BUFFER - 1] = LINE_SENTRY;/*enter array sentry at end of array*/
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void setRight(struct node *this, struct node *next)
{
    this->right = next;
}
void setLeft(struct node *this, struct node *next)
{
    this->left = next;
}
void setLine(struct node *this, int line)
{
    int i;
    int *newLines;
    for (i = 0; this->lines[i] != LINE_SENTRY && this->lines[i] != line; i++)/*find an empty cell to enter new line*/
    {
        if (this->lines[i] == 0)
        {
            this->lines[i] = line;
            return;
        }
    }
    if (this->lines[i] == LINE_SENTRY)/*if no empty cell was found make room */
    {
        newLines = realloc(this->lines, (intArrLength(this->lines) + LINE_BUFFER) * sizeof(int));/*add aditional buffer size space to array*/
        if (this->lines == NULL)/*check for successfull relocation of memory*/
        {
            fprintf(stderr, "Error reallocating memory");
            exit(EXIT_FAILURE);
        }
        else
        {
            this->lines = newLines;
            this->lines[intArrLength(this->lines) + LINE_BUFFER - 1] = LINE_SENTRY;/*move sentry to new last place in array*/
            this->lines[i] = line;
        }
    }
}
void freeNode(struct node *this)
{
    free(this->token);
    free(this->lines);
    free(this);
}
int intArrLength(int *arr)
{
    int counter = 0;
    while (*arr != LINE_SENTRY)
    {
        counter++;
        arr++;
    }
    return counter;
}
void zeroArray(int *arr, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        arr[i] = 0;
    }
}