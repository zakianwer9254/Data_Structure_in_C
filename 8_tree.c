/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node{
	int value;
	struct node *left, *right;
};

struct node *root = NULL;
//struct node *p=root;

void makeTree(struct node *p,char *str,int i){
	struct node * temp= (struct node*)malloc(sizeof(struct node));
	
	if(str[i]=='('){
		makeTree(p->left,str,++i);
		makeTree(p->right,str,++i);
		i++;
		return
	}
	if(str[i]==')' || str[i]=='\0')
		return

	temp->value=str[i]
	temp->left=NULL;
	temp->right=NULL;
	p=temp;


	temp->value=str[i]
	temp->left=NULL;
	temp->right=NULL;
	p->left=temp;

	temp->value=str[i+1]
	temp->left=NULL;
	temp->right=NULL;
	p->right=temp;
	i++;
}


int main(){
	printf("enter nodes level wise, * for null\n");
	char *str = (char*)malloc(sizeof(char));
	int temp=0;
	int c,i=0;
	while((c=getchar())!=EOF){
		str[i++]=c;
		str=realloc(str,i+sizeof(char));
	}

	makeTree(root,str,0);

	printf("%s\n",str);

}

