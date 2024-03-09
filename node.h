#define LINE_BUFFER 5 /*buffer size for initial line array and each new memory alocation enlargement*/
#define LINE_SENTRY -1 /*all lines array cells are 0 or larger ,-1 represents the last cell of array*/
#define BIGGER 1;
#define SMALLER -1;
#define EQUAL 0;

struct node/*treeNode with data of token,and line array*/
{
    char *token;
    int *lines;
    struct node *left;
    struct node *right;
};
struct node *newNode(char *token);/*returns a pointer to a new tree node with token placed inside*/
void setRight(struct node *this, struct node *next);/*sets the right child of a tree node*/
void setLeft(struct node *this, struct node *next);/*sets the left child of a tree node*/
void setLine(struct node *this, int line);/*sets a new line into array and enlarges the array if there is no room for new lines*/
void freeNode(struct node *this);/*frees all parts of a node struct and then the node struct itself*/
int intArrLength(int *arr);/*returns the number of elements in a integer array*/
void zeroArray(int *arr,int length);/*turns all cells in array to 0*/