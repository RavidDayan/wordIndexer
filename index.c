#include <stdio.h>
#include <string.h>
#include <ctype.h>

void indexer(/*char *name*/);
int getMaxLineLength(FILE *file_pointer);
int getMaxWordLength(FILE *file_pointer);
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
    FILE *file_pointer;
    file_pointer = fopen("input.txt", "r");
    /*printf("%d", getMaxLineLength(file_pointer));*/
    rewind(file_pointer);
    printf("%d", getMaxWordLength(file_pointer));
}
int getMaxLineLength(FILE *file)
{
    char ch;       /*hold current char*/
    int start = 0; /*index of the start of the line*/
    int end = 0;   /*index of the end of the line*/
    int max = 0;   /*length of longest line*/
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            if (max < end - start)
            {
                max = end - start;
            }
            start = end + 1; /*move to start of next line*/
        }
        end++;
    }
    /*check the last line */
    if (max < end - start)
    {
        max = end - start;
    }
    return max;
}
int getMaxWordLength(FILE *file)
{
    char ch; /*hold current char*/
    int counter = 0;
    int max = 0; /*length of longest line*/
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
    return max;
}