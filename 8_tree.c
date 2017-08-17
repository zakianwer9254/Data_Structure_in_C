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


struct node* insert(struct node *p, int ans){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(ans==-1)
		p=NULL;
	else{
		temp->value=ans;
		temp->left=NULL;
		temp->right=NULL;
		p=temp;
	}
	return p;
}

void traverse(struct node *p){
	while(p!=NULL){
		traverse(p->left);
		printf("%d ",p->value);
		traverse(p->right);
	}
}

void makeTree(char *s,struct node *p){

	int ans;
	int temp;
	while((ans=get(s))!=EOF){
		if(ans=='('){
			ans=get(s);
			temp=atoi(s);
			p=insert(p,temp);
			
			makeTree(s,p->left);
			makeTree(s,p->right);
			return;
		}
		else if(ans=='0'){
			p=insert(p,atoi(s));
			
			return;
		}
		else if(ans=='*'){
			insert(p,-1);
			return;
		}		
	}
}

int main(){

	char *s;
	int ans,val;
	s=(char *)malloc(sizeof(char));

	struct node *p = root;
	
	makeTree(s,p);

	traverse(root);

	return 0;
}
int buffer=0;
int get(char *s){
	int i=0,c,size=1;
	s=(char *)realloc(s,++size*sizeof(char));
	while((s[i]=c=getch())==' ' || c=='\t');
	s[1]='\0';
	if(!isdigit(c))
		return c;
	if(isdigit(c)){
		s=(char *)realloc(s,++size*sizeof(char));
		while(isdigit(s[++i]=c=getch()))
			s=(char *)realloc(s,++size*sizeof(char));
	}
	s[++i]='\0';
	if(c!=EOF)
		ungetch(c);
	return '0';
}

void getch(){
	if(buffer!=0){
		int x=buffer;
		buffer=0;
		return x;
	}
	else
		getchar();
}

void ungetch(c){
	buffer=c;
}