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




int main(){

	int x='a';
	if(x==97)
		printf("%d\n",')');
	else
		printf("something\n");

	char *s;
	int ans,val;
	s=(char *)malloc(sizeof(char));
	
	while((ans=get(s))!=EOF){
		int temp;
		switch(ans){
			case '0':
			printf("%d\n",atoi(s));
			break;
			case '(':
			printf("its +\n");
			break;
			case ')' :
			printf("its -\n");
			break;
			default:
			printf("others\n");

		}
	}

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