/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int MAX_LENGTH=10;
int STACK_LENGTH=4;

int top=-1;

int main(){
	char *str=(char *)malloc(MAX_LENGTH*sizeof(char));
	char *string=(char *)malloc(STACK_LENGTH*sizeof(char));
	
	int c;
	int j=0;
	while((c=getchar())!='\n' && c!=EOF){
		str[j]=(char)c;
		j++;
		if(j==MAX_LENGTH){
			MAX_LENGTH*=2;
			str = (char *)realloc(str,MAX_LENGTH*sizeof(char));
		}
	}
	int flag=0;
	for(int i=0; i<j; i++)
		printf("%c",str[i]);
	printf("\n");
	for(int i=0; i<j; i++){
		switch(str[i]){
			case '[':
			case '{':
			case '(':
			push(string,str[i]);
			break;
			case ']':
			if(top>=0 && string[top]=='['){
				pop(string);
			}
			else{
				flag=1;
				printf("Invalid Expression\n");
				break;
			}
			break;
			case '}':
			if(top>=0 && string[top]=='{'){
				pop(string);
			}
			else{
				flag=1;
				printf("Invalid Expression\n");
				break;
			}
			break;
			case ')':
			if(top>=0 && string[top]=='('){
				pop(string);
			}
			else{
				flag=1;
				printf("Invalid Expression\n");
				break;
			}
			break;
		}
		if(flag==1)
			break;
	}


	if(flag==0){
		if(top==-1)
			printf("Expression is valid\n");
		else
			printf("Invalid Expression\n");
	}


	return 0;
}

void push(char *string, char ch){
	top++;
	string[top]=ch;
	if(top+1==STACK_LENGTH){
		STACK_LENGTH*=2;
		string=(char*)realloc(string,STACK_LENGTH*sizeof(char));
	}
	//printf("character added is %c\n",string[top]);
}

void pop(char *string){
	top--;
	if(top+2<=STACK_LENGTH/4){
		STACK_LENGTH/=4;
		string=(char*)realloc(string,STACK_LENGTH*sizeof(char));
	}
	//printf("character deleted : %c\n",string[top+1]);
}

void show_stack(char *string){
	for(int i=0; i<=top; i++)
		printf("%c",string[i]);
}



