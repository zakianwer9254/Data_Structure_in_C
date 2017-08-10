/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int coef;
	int exp;
	struct node *next;
};

struct node *head[4];


void insert(int x, int y, int i){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(head[i]==NULL){
		temp->coef=x;
		temp->exp=y;
		temp->next=NULL;
		head[i]=temp;
	}
	else{
		struct node *p=head[i];

		while(p->next!=NULL){
			if(p->next->exp>y){
				p=p->next;
				continue;
			}
			if(p->next->exp<y){
				temp->coef=x;
				temp->exp=y;
				temp->next=p->next;
				p->next=temp;
				break;
			}
			if(p->next->exp==y){
				p->next->coef+=x;
				break;
			}
		}
		if(p->next==NULL){
			if(p->exp>y){
				temp->coef=x;
				temp->exp=y;
				temp->next=NULL;
				p->next=temp;
			}
			else if(p->exp<y){
				temp->coef=x;
				temp->exp=y;
				temp->next=p;
				head[i]=p;
				//break;
			}
			else if(p->exp==y){
				p->coef+=x;
				//break;
			}
		}



		
	/*	while(p->next!=NULL){

			p=p->next;
		}
		temp->coef=x;
		temp->exp=y;
		temp->next=NULL;
		p->next=temp;
	}*/
}
}

void add_poly(int x, int y, int length_1, int length_2){
	struct node *p = head[x];
	struct node *q = head[y];
	
		while(p!=NULL && q!=NULL){
			if(p->exp>q->exp){
				insert(p->coef,p->exp,2);
				p=p->next;
				continue;
			}

			if(p->exp<q->exp){
				insert(q->coef,q->exp,2);
				q=q->next;
				continue;
			}

			if(p->exp==q->exp){
				insert(p->coef+q->coef,p->exp,2);
				p=p->next;
				q=q->next;
				//i++;
				continue;
			}
			
		}

	while(q!=NULL){
		insert(q->coef,q->exp,2);
		q=q->next;
	}
	while(p!=NULL){
		insert(p->coef,p->exp,2);
		p=p->next;
	}
}


void multiply(int x, int y, int l1, int l2){
	struct node *p = head[x];
	
	for(int i=0; i<l1; i++){
		struct node *q = head[y];
		for(int j=0; j<l2; j++){
			insert(p->coef*q->coef,p->exp+q->exp,3);
			q=q->next;
		}
		p=p->next;
	}
}



void result(int i){
	struct node *p=head[i];
	while(p!=NULL){
		printf("%dx^%d",p->coef,p->exp);
		if(p->next!=NULL)
			printf("+");
		p=p->next;
	}
}

int main(){

	for(int i=0; i<4; i++)
		head[i]=NULL;

	int length_first,length_second,x,y;
	printf("Polynomial 1 :\n");
	printf("Total number of terms : ");
	scanf("%d",&length_first);

	for(int i=0; i<length_first; i++){
		printf("coefficient and exponent : ");
		scanf("%d %d",&x,&y);
		insert(x,y,0);
	}

	printf("\n");
	printf("Polynomial 2 :\n");
	printf("Total number of terms : ");
	scanf("%d",&length_second);

	for(int i=0; i<length_second; i++){
		printf("coefficient and exponent : ");
		scanf("%d %d",&x,&y);
		insert(x,y,1);
	}

	add_poly(0,1,length_first,length_second);

	result(2);

	multiply(0,1,length_first,length_second);
	printf("\n");
	result(3);

	return 0;
}