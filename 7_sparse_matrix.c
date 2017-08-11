/* Singly Linked List Implementation */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node{
	int index;
	int value;
	struct node * next;
};

struct node *head[];

int n;


void insert(int x, int y, int z){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->index=y;
	temp->value=z;
	if(head[x]==NULL){
		temp->next=NULL;
		head[x]=temp;
	}
	else{
		struct node *p = head[x];
		while(p->next!=NULL){
			if(p->next->index>y){
				temp->next=p->next;
				p->next=temp;
				continue;
			}
			if(p->next->index<y ){
				p=p->next;
			}
		}
		if(p->next==NULL){
			if(p->index<y){
				temp->next=NULL;
				p->next=temp;
			}
			else{
				temp->next=p;
				head[x]=temp;
			}
		}
	}
}

void show(int x, int n){
	struct node *p = head[x];
	while(p!=NULL){
		printf("%d %d %d\n",x%n,p->index,p->value);
		p=p->next;
		
	}
	
}

void add(int x, int y, int z){
	int temp=y;
	while(temp>0){
		temp--;
		struct node *p = head[x];
		struct node *q = head[y];
		//struct node *r = head[z];
		
		while(p!=NULL && q!=NULL){	
				if(p->index<q->index){
					insert(z,p->index,p->value);
					p=p->next;
				}
				else if(p->index>q->index){
					insert(z,q->index,q->value);
					q=q->next;
				}
				else if(p->index==q->index){
					insert(z,p->index,p->value+q->value);
					p=p->next;
					q=q->next;
				}
		}

		while(p!=NULL){
			insert(z,p->index,p->value);
			p=p->next;
		}
		while(q!=NULL){
			insert(z,q->index,q->value); 
			q=q->next;
		}
		x++;
		y++;
		z++;

	}

}

int main(){
	int no_of_elements;
	printf("Matrix dimension : ");
	scanf("%d",&n);
	for(int i=0; i<3*n; i++){
		head[i]=NULL;
	}

	printf("\nTotal Number of elements - Matrix 1 : ");
	scanf("%d",&no_of_elements);

	int x,y,z;
	for(int i=0; i<no_of_elements; i++){
		printf("put index i,j and value : ");
		scanf("%d %d %d",&x,&y,&z);
		insert(x,y,z);
	}

	printf("\nTotal Number of elements - Matrix 2 : ");
	scanf("%d",&no_of_elements);

	for(int i=0; i<no_of_elements; i++){
		printf("put index i,j and value : ");
		scanf("%d %d %d",&x,&y,&z);
		insert(x+n,y,z);
	}


	//printf("ok\n");
	


	add(0,n,2*n);

	printf("\n");
	for(int i=0; i<n; i++){
		show(i,n);
	}
	printf("\n");
	for(int i=n; i<2*n; i++)
		show(i,n);
	printf("\n");
	for(int i=2*n; i<3*n; i++)
		show(i,n);



	return 0;
}