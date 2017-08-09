/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int coefficient;
	//int exponent;
	struct node *next;
};

struct node *head=NULL;
struct node *head2=NULL;
struct node *head3=NULL;

void insert(int x,int i){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(i==0){
		if(head==NULL){
		temp->coefficient=x;
		temp->next=NULL;
		head=temp;
		}
		else{
			struct node *p = head;
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=temp;
			temp->coefficient=x;
			//p->next->exponent=y;
			temp->next=NULL;
		}
	}
	else if(i==1){
		if(head2==NULL){
		temp->coefficient=x;
		temp->next=NULL;
		head2=temp;
		}
		else{
			struct node *p = head2;
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=temp;
			temp->coefficient=x;
			//p->next->exponent=y;
			temp->next=NULL;
		}
	}
	else if(i==2){
		if(head3==NULL){
		temp->coefficient=x;
		temp->next=NULL;
		head3=temp;
		}
		else{
			struct node *p = head3;
			while(p->next!=NULL){
				p=p->next;
			}
			p->next=temp;
			temp->coefficient=x;
			//p->next->exponent=y;
			temp->next=NULL;
		}
	}
}

void add_polynomial(struct node *head, struct node *head2, int max){
	struct node *p1 = head;
	struct node *p2 = head2;
	int x,y;
	while(max>=0){
		if(p1!=NULL){
			x=p1->coefficient;
			p1=p1->next;
		}
		else
			x=0;
		
		if(p2!=NULL){
			y=p2->coefficient;
			p2=p2->next;
		}
		else
			y=0;

		insert(x+y,2);
		max--;
		
	}
show_result();
}

void show_result(){
	struct node *p = head3;
	int i=0;
	while(p!=NULL){
		printf("%dx^%d",p->coefficient,i);
		if(p->next!=NULL)
			printf(" + ");
		p=p->next;
		i++;
	}
}


int main(){
	int exp1,exp2;
	printf("Polynomial 1: \n");
	printf("Maximum exponent : ");
	scanf("%d",&exp1);
	for(int i=0; i<=exp1; i++){
		printf("coefficient of x^%d : ",i);
		int cc;
		scanf("%d",&cc);
		insert(cc,0);
	}

	printf("Polynomial 2: \n");
	printf("Maximum exponent :");
	scanf("%d",&exp2);
	for(int i=0; i<=exp2; i++){
		int cc;
		printf("coefficient of x^%d : ",i);
		
		scanf("%d",&cc);
		insert(cc,1);
	}

	add_polynomial(head,head2,exp1>exp2?exp1:exp2);

	



	

}