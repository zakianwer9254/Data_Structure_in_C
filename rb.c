#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

#define BLACK 1
#define RED 0

struct node{
	struct node *p;
	struct node *left;
	struct node *right;
	int key;
	bool color;		// black==1,  red==0
};

struct node *root=NULL;

struct node *NIL=NULL;


/*
struct node* sentinel(){
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->key=NULL;
	temp->left=NULL;
	temp->right=NULL;
	temp->p=NULL;
	temp->color=BLACK;

	return temp;
}*/

struct node* newNode(int x){
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->key=x;
	temp->p=NIL;
	temp->left=NIL;
	temp->left->p=temp;
	temp->right=NIL;
	temp->right->p=temp;
	temp->color=RED;		// 0 is red,   black=1;

	return temp;
}

struct node* initialize(struct node *root, int x){
	root=newNode(x);
	root->color=BLACK;
	return root;
}

struct node * left_rotate(struct node *r, struct node * s){
		
	r->right=s->left;
	if(s->left!=NIL)
		r->right->p=r;
	if(r->p==NIL)
		s->p=root;
	else if(r->p->left==r)
		r->p->left=s;
	else if(r->p->right==r)
		r->p->right==s;
	s->left=r;
	s->p=r->p;
	r->p=s;

	return s;
}

struct node * right_rotate(struct node *y, struct node * s){
	struct node *x;
	x=y->left;
	y->left=x->right;
	if(x->right!=NIL)
		x->right->p=y;
	x->p=y->p;
	if(y->p==NIL)
		root=x;
	else if(y==y->p->right)
		y->p->right=x;
	else
		y->p->left=x;
	x->right=y;
	y->p=x;
	return x;
}


void fix_insert(struct node *t){

	struct node *z=t;

	while(z->p!=NIL && z->p->color==RED){
			if(z->p==z->p->p->left){
				struct node *uncle=z->p->p->right;
				if(uncle->color==RED){
					z->p->p->right->color=BLACK;
					z->p->color=BLACK;
					z->p->p->color=RED;
					z=z->p->p;
				}
				else{
					if(z->p->right==z){
						z->p=left_rotate(z->p,z);
					}
					z->p->color=BLACK;
					z->p->p->color=RED;
					z=right_rotate(z->p->p,z->p);
					z=z->p;
				}
			}
			else{
				struct node *uncle=z->p->p->left;
				if(uncle->color==RED){
					z->p->p->left->color=BLACK;
					z->p->color=BLACK;
					z->p->p->color=RED;
					z=z->p->p;
				}
				else{
					if(z->p->left==z){
						z->p=right_rotate(z->p,z);
					}
					z->p->color=BLACK;
					z->p->p->color=RED;
					z->p->p=left_rotate(z->p->p,z->p);
					z=z->p;
				}
			}
	}

	z->color=BLACK;
	
}



struct node * insert(struct node *t, struct node *par, int x){
	
	if(t==NIL){
		struct node *new=newNode(x);
		new->p=par;
		if(new->p->color==RED)
		fix_insert(new);
		return new;
	}
	if(x>t->key)
		t->right=insert(t->right,t,x);
	else
		t->left=insert(t->left,t,x);

	return t;

}

void traverse(struct node *t){
	if(t!=NIL){
		traverse(t->left);
		printf("%d:%d ",t->key,t->color);
		traverse(t->right);
	}
}

int main(){
	
	NIL=(struct node *)malloc(sizeof(struct node));
	NIL->color=BLACK;
	//root=sentinel();
	printf("0: initialize,  1: insert,  2: traverse,  3: delete,  4:quit ");

	int ch;
	int x,quit=1;
	
	while(quit!=0){
		printf("\nEnter you choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:
			scanf("%d",&x);
			root=initialize(root,x);
			break;
			case 1:
			scanf("%d",&x);
			root=insert(root,root->p,x);
			break;
			case 2:
			traverse(root);
			break;
			case 3:
			//scanf("%d",&x);
			//delete(x);
			break;
			case 4:
			quit=0;
			break;
		}
		//printf("\nsize of structure: %d",sizeof(root));
	}
	
	return 0;
}


























