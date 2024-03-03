#define LINE_BUFFER 5
#define LINE_SENTRY -1
#define BIGGER 1;
#define SMALLER -1;
#define EQUAL 0;
struct node
{
    char *name;
    int *lines;
    struct node *left;
    struct node *right;
};
struct node *newNode(char *name);
void setNext(struct node *this, struct node *next);
void setLine(struct node *this, int line);
struct node *getNext(struct node *this);
char *getName(struct node *this);
int *getLines(struct node *this);
void freeNode(struct node *this);
int compareNode(struct node *this,struct node *other);