struct node *insert(struct node *tree, char *newToken, int line);
/*inserts a new token and the line it apeard in, if new token is equal to current token add the line to
current token,if its lexographicly bigger move to the right child if its smaller move to the left child */
void maxToMinFunc(struct node *tree); /*prints the tree using in order traversal alogorithem*/
void freeTree(struct node *tree);     /*frees the memory of each node using post order traversal*/
