#define LINE_BUFFER 5
#define LINE_SENTRY -1
struct node
{
    char *name;
    int *lines;
    struct node *next;
};
struct node *newNode(char *name);
void setNext(struct node *this, struct node *next);
void setLine(struct node *this, int line);
struct node *getNext(struct node *this);
char *getName(struct node *this);
int *getLines(struct node *this);
void freeNode(struct node *this);