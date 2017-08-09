/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int value;
	struct node *next;
};

struct node *head = NULL;




void insertNode(int key){
	struct node *temp = (struct node * )malloc(sizeof(struct node));

	if(head==NULL){
		temp->value=key;
		temp->next = NULL;
		head=temp;
	}
	else{
		struct node *p = head;
		p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		temp->value=key;
		temp->next = NULL;
		p->next=temp;
	}
}

void traverse(){
	struct node *p = head;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}






void deleteNode(int key){
	struct node *p = head;
	if(p->value==key){
		head=p->next;
		free(p);
		printf("node deleted\n");
	}
	else{
		while(p->next!=NULL){
			if(p->next->value==key){
				struct node *q = (struct node*)malloc(sizeof(struct node*));
				q=p->next;
				p->next=q->next;
				free(q);
				printf("node deleted\n");
				break;
			}
			p=p->next;
		}
	}
}

bool isPresent(key){
	struct node *p = head;
	if(p->value==key){
		return true;
	}
	else{
		while(p->next!=NULL){
			if(p->next->value==key){
				return true;
			}
			p=p->next;
		}
	}
	return false;
}

int getElement(int index){
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p=head;
	int i=0;
	while(p!=NULL){
		if(i==index){
			return p->value;
			break;
		}
		else{
			i++;
			p=p->next;
		}
	}
	printf("not found\n");
	return 0;
}

int main()
{
	
	printf("Function Specifications are : \n");
   	printf("insertNode(key)\n");
   	printf("deleteNode(key)\n");
   	printf("isPresent(key)\n");
   	printf("traverse()\n");
   	printf("getElement(index)\n");
   	insertNode(5);
   	insertNode(6);
   	insertNode(9);
   	insertNode(8);
   	//insertNode(10);
   	traverse();
   	deleteNode(8);
   	traverse();
   	if(isPresent(7))
   		printf("Yes it exist\n");
   	else
   		printf("not exist\n");
   	//isPresent(9);
   	//isPresent(7);
   	printf("%d",getElement(2));
   	printf("%d",getElement(3));
   	//printf("%d",getElement(4));
}


