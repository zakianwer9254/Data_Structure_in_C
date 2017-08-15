/* Singly Linked List Implementation */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node{
	int value;
	struct node *next, *prev;
};

struct node *tail = NULL, *head=NULL;

void insert(int x){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->value=x;
	if(tail==NULL){
		temp->next=temp;
		temp->prev=temp;
		tail=temp;
		head=temp;
	}
	else{
		temp->next=tail;
		head->next=temp;
		temp->prev=head;
		head=temp;
	}
}

show()

int main(){

	/*
	 * Setting sentinel node
	 */

	struct node *temp =(struct node*)malloc(sizeof(struct node));
	temp->value=0;
	temp->next=temp;
	temp->prev=temp;
	head=temp;
	tail=temp;

	
	
	push(6);
	push(7);
	push(3);

	show();

	return 0;
}