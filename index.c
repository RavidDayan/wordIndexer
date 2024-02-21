#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void indexer(/*char *name*/);
int getMaxWordLength(FILE *file_pointer);
int getTokenFromInput(char *des, int tokenLength, int *lineIndex, FILE *file);
void placeWord(char *token, int index, FILE *file);
int main(int argc, char *argv[])
{

    indexer();
    /*int i;
    for (i = 0; i < argc; i++)
    {
        indexer(argv[i]);
    }*/
    return 0;
}
void indexer(/*char *fileName*/)
{
    char tokens[200][80];
    char token[80];
    int lines[200][200];
    int tokenLength;
    int lineIndex = 1;
    int futureLineIndex = 1;
    int i = 0;
    int j = 0;
    FILE *fileInput;
    /*FILE *fileOutput;*/
    fileInput = fopen("input.txt", "r");
    /*fileOutput = fopen("output.txt", "w+");*/
    tokenLength = getMaxWordLength(fileInput);
    while (getTokenFromInput(token, tokenLength, &futureLineIndex, fileInput) != 0)
    {
        printf("%s ", token);
        printf("%d\n", lineIndex);
        lineIndex = futureLineIndex;
    }
    printf("%s ", token);
    printf("%d\n", lineIndex);
    lineIndex = futureLineIndex;
}

int getTokenFromInput(char *des, int tokenLength, int *lineIndex, FILE *file)
{
    int i = 0;
    char ch;
    ch = getc(file);
    while (ch != EOF)
    {
        if (isspace(ch) != 0)
        {
            if (ch == '\n')
            {
                (*lineIndex)++;
            }
            return 1;
        }
        des[i] = ch;
        des[i + 1] = '\0';
        i++;
        ch = getc(file);
    }
    return 0;
}
int getMaxWordLength(FILE *file)
{
    char ch; /*hold current char*/
    int counter = 0;
    int max = 0; /*length of longest line*/
    rewind(file);
    while ((ch = fgetc(file)) != EOF)
    {
        if (isspace(ch) == 0)
        {
            counter++;
        }
        else
        {
            if (max < counter)
            {
                max = counter;
            }
            counter = 0;
        }
    }
    if (max < counter)
    {
        max = counter;
    }
    counter = 0;
    rewind(file);
    return max;
}