#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

int buffer=0;

struct node{
	int value;
	struct node *left;
	struct node *right;
};





struct node * newNode(int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->value=x;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

struct node* insert(struct node *p, int x){
	if(p==NULL)
		return newNode(x);
	if(p->value>x)
		p->left=insert(p->left,x);	
	else if(p->value<x)
		p->right=insert(p->right,x);
	
	return p;
}




void traverse(struct node *p){
	if(p!=NULL){
		traverse(p->left);
		printf("%d ",p->value);
		traverse(p->right);
	}
}


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
	if(isdigit(s[++i]=c=getch())){
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
	x=getInput(s);
	root=insert(root,atoi(s));
	
	printf("Enter value to be inserted, press q to exit");
	while((x=getInput(s))!='q'){
		insert(root,atoi(s));
	}

	traverse(root);

}