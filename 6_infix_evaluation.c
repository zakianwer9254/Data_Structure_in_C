/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int MAX_LENGTH=10;
int store_length=4;

int top=-1;



void solve(char *str, int *value,int start_index, char *store){
	
	int i=0;
	int j=0;
	while(str[i]!='\0'){
		int temp=0;
		int flag=0;
		while(str[i]>='0' && str[i]<='9' && str[i]!='\0'){
			temp=temp*10+(str[i]-'0');
			flag=1;
			i++;
		}
		if(flag!=0)
			value[j++]=temp;
		
		if(str[i]=='*' || str[i]=='/'){
			if(top==-1 || store[top]=='+' || store[top]=='-' || store[top]=='('){
				push(store,str[i]);
				i++;
				continue;
			}
			else{
				if(store[top]=='*'){
					value[j-2]=value[j-2]*value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					//printf("mult before mult %d\n",value[j-1]);
					continue;
				}
				if(store[top]=='/'){
					value[j-2]=value[j-2]/value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					continue;
				}
			}

		}
		else if(str[i]=='+' || str[i]=='-'){

			if(top==-1 || store[top]=='('){
				push(store,str[i]);
				i++;
				continue;
			}
			else{
				if(store[top]=='*'){
					value[j-2]=value[j-2]*value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					continue;
				}
				if(store[top]=='/'){
					value[j-2]=value[j-2]/value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					continue;
				}
				if(store[top]=='+'){
					value[j-2]=value[j-2]+value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					continue;
				}
				if(store[top]=='-'){
					value[j-2]=value[j-2]-value[j-1];
					j--;
					pop(store);
					push(store,str[i]);
					i++;
					continue;
				}

			}
		}
		else if(str[i]=='('){
			push(store,str[i]);
			//printf("( stored");
			i++;
			continue;
		}
		else if(str[i]==')'){
			while(store[top]!='('){
				if(store[top]=='+'){
					value[j-2]=value[j-2]+value[j-1];
					j--;
					pop(store);
					continue;
				}
				if(store[top]=='-'){
					value[j-2]=value[j-2]-value[j-1];
					j--;
					pop(store);
					continue;
				}
				if(store[top]=='*'){
					value[j-2]=value[j-2]*value[j-1];
					j--;
					pop(store);
					continue;
				}
				if(store[top]=='/'){
					value[j-2]=value[j-2]/value[j-1];
					j--;
					pop(store);
					continue;
				}
				//pop(store);				
			}
			pop(store);
			i++;
			continue;
		}
		
	}
	while(top!=-1){
				if(store[top]=='+'){
					value[j-2]=value[j-2]+value[j-1];
					j--;
				}
				if(store[top]=='-'){
					value[j-2]=value[j-2]-value[j-1];
					j--;
				}
				if(store[top]=='*'){
					value[j-2]=value[j-2]*value[j-1];
					j--;
				}
				if(store[top]=='/'){
					value[j-2]=value[j-2]/value[j-1];
					j--;
				}
				pop(store);				
			}
}	


void push(char *store, char ch){
	top++;
	store[top]=ch;
	if(top+1==store_length){
		store_length*=2;
		store=(char*)realloc(store,store_length*sizeof(char));
	}
	//printf("character added is %c\n",string[top]);
}

void pop(char *store){
	top--;
	if(top+2<=store_length/4){
		store_length/=4;
		store=(char*)realloc(store,store_length*sizeof(char));
	}
	//printf("character deleted : %c\n",string[top+1]);
}




int main(){
	char *str=(char *)malloc(MAX_LENGTH*sizeof(char));
	
	
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

	int *value=(int *)malloc(j*sizeof(int));
	char *store=(char *)malloc(store_length*sizeof(char));

	solve(str,value,0,store);

	printf("%d",value[0]);
	return 0;
}