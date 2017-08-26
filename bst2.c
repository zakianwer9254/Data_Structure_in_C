#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int buffer=0;

struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}
  
// Driver Program to test above functions
int getch(){
    if(buffer>0){
        int x=buffer;
        buffer=0;
        return x;
    }
    else getchar();
}

void ungetch(int c){
    buffer=c;
}


char getInput(char *s){
    int size=1;
    int c;
    int i=0;
    while((s[0]=c=getch())==' ' || c=='\t');
    s=realloc(s,sizeof(char)*(++size));
    s[1]='\0';
    if(!isdigit(c))
        return c;
    s=realloc(s,sizeof(char)*(++size));
    if(isdigit(c)){
        s=realloc(s,sizeof(char)*(++size));
        while(isdigit(s[++i]=c=getch()))
            s=realloc(s,sizeof(char)*(++size));
    }
    s[i]='\0';
    if(c!=EOF){
        ungetch(c);
    }
    return '0';
}




int main(){
    int x;
    char *s=(char *)malloc(sizeof(char));
    struct node *root=NULL;
    printf("insert first node: \n");
    scanf("%d",&x);
    root = insert(root,x);

    printf("Enter value to be inserted, press q to exit");
    scanf("%d",&x);
    while(x!=-1){
        insert(root,x);
        scanf("%d",&x);
    }
    //struct node *root=NULL;
    //root = insert(root, 2);
    insert(root, 3);
    insert(root, 1);
    
  
    // print inoder traversal of the BST
    inorder(root);
  
    return 0;
}