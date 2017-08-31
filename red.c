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

struct node * left_rotate(struct node *y, struct node * s){
	
	struct node *x;
	x=y->right;
	y->right=x->left;
	if(x->left!=NIL)
		x->left->p=y;
	x->p=y->p;
	if(y->p==NIL)
		root=x;
	else if(y==y->p->left)
		y->p->left=x;
	else
		y->p->right=x;
	x->left=y;
	y->p=x;
	return x;
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
						left_rotate(z->p,z);
					}
					z->p->color=BLACK;
					z->p->p->color=RED;
					right_rotate(z->p->p,z->p);
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
						right_rotate(z->p,z);
					}
					z->p->color=BLACK;
					z->p->p->color=RED;
					left_rotate(z->p->p,z->p);
					z=z->p->p;
				}
			}
	}

	root->color=BLACK;
	
}



void insert(struct node *t, int x){

	
	struct node *z=t;
	struct node *y=z;
	int c;

	while(z!=NIL){
		y=z;
		if(x>z->key){
			c=0;
			z=z->right;
		}
		else{
			c=1;
			z=z->left;
		}
	}

	struct node *new=newNode(x);
	new->p=y;
	
	if(c==0)
		y->right=new;
	else 
		y->left=new;
	if(new->p->color==RED)
		fix_insert(new);
	

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
			insert(root,x);
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
