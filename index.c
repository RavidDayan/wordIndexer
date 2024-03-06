#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "node.h"
#include "tree.h"

void indexer(char *name);             /*iterate over file and index's words and lines*/
char *getTokenFromInput(FILE *file);  /*returns a token from file by finding the current token length,alocating memory and inserting the chars from file*/
int stringLength(FILE *file);         /*returns the length of the current token in file by counting the number of chars in file until whitespace or EOF is encounterd,rewinds file pointer back to the start of the word*/
int findToken(FILE *file, int *line); /*iterates over whitespaces in file until a token or EOF is reached return 1 if a non whitespace char is found,0 if reached EOF*/
int main(int argc, char *argv[])
{
    int i;
    if (argc == 1)
    {
        fprintf(stderr, "No file name has been enterd");
        exit(0);
    }

    for (i = 1; i < argc; i++)
    {
        printf("%s", argv[i]);
        indexer(argv[i]);
    }

    return 0;
}
void indexer(char *fileName)
{
    struct node *tree = NULL;
    char *token = NULL;
    FILE *fileInput;
    int lineIndex = 1;
    fileInput = fopen(fileName, "r");
    if (fileInput == NULL)
    {
        fprintf(stderr, "file named %s could not be opend\n", fileName);
        exit(0);
    }

    while (findToken(fileInput, &lineIndex) != 0)
    {
        token = getTokenFromInput(fileInput);
        tree = insert(tree, token, lineIndex);
    }
    maxToMinFunc(tree);
    freeTree(tree);
}

char *getTokenFromInput(FILE *file)
{
    int i;
    int tokenSize; /*size of current token*/
    char *des;     /*returned string*/
    tokenSize = stringLength(file);
    des = (char *)malloc((tokenSize + 1) * sizeof(char)); /*alocate memory for current token and room for '\n'*/
    if (des == NULL)
    {
        fprintf(stderr, "Error allocating memory");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < tokenSize; i++)
    {
        des[i] = getc(file);
    }
    des[i] = '\0';
    return des;
}
int stringLength(FILE *file)
{
    char ch = 'a';   /*holds chars from file*/
    int counter = 0; /*counter for string length*/
    ch = getc(file);
    while (ch != EOF && isspace(ch) == 0)
    {
        counter++;
        ch = getc(file);
    }
    if (ch == EOF)
    {
        fseek(file, -(counter), SEEK_CUR);
    }
    else
    {
        fseek(file, -(counter + 1), SEEK_CUR);
    }
    return counter;
}
int findToken(FILE *file, int *line)
{
    char ch = ' '; /*hold file chars*/
    while (ch != EOF && isspace(ch) != 0)
    {
        ch = getc(file);
        if (ch == '\n') /*increments the line when \n is met*/
        {
            *line = *line + 1;
        }
    }
    if (isspace(ch) == 0 && ch != EOF)
    {
        fseek(file, -1, SEEK_CUR); /*rewind file pointer to current character in ch*/
        return 1;
    }
    else
    {
        return 0;
    }
}