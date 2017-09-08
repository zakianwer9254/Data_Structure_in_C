#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct node{
	int key;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;
struct node *root2=NULL;
struct node *t_1=NULL;
struct node *t_2=NULL;
struct node *NIL;


struct node* newNode(int x){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=x;
	temp->left=NIL;
	temp->right=NIL;

	return temp;
}

struct node* initialize(struct node *root, int x){
	root=newNode(x);

	return root;
}


struct node* insert(struct node *t, int x, struct node *root){
	if(root==NIL){
		root=initialize(root,x);
		return root;
	}

	if(t==NIL){
		t=newNode(x);
		return t;
	}
	if(t->key<x){
		t->right=insert(t->right,x,root);
	}
	if(t->key>=x){
		t->left=insert(t->left,x,root);
	}

	return t;
}

void traverse(struct node *t, struct node *root){
	if(root==NIL)
		printf("\nNo Element");
	if(t!=NIL){
		traverse(t->left,root);
		printf("%d ",t->key);
		traverse(t->right,root);
	}
}

struct node * inorder_successor(struct node *t){
	if(t->left!=NIL)
		return inorder_successor(t->left);
	return t;
}

struct node* delete(struct node *t, int x){
	if(t==NIL){
		printf("Element not exist\n");
		return t;
	}
	if(t->key<x){
		t->right=delete(t->right,x);
	}
	else if(t->key>x){
		t->left=delete(t->left,x);
	}
	else{
		if(t->left==NIL && t->right==NIL){
			free(t);
			t=NIL;
		}
		else if(t->left==NIL){
			struct node *temp=t;
			t=t->right;
			free(temp);
		}
		else if(t->right==NIL){
			struct node *temp=t;
			t=t->left;
			free(temp);
		}
		else{
			struct node *temp=inorder_successor(t->right);
			t->key=temp->key;
			t->right=delete(t->right,temp->key);
		}
	}

	return t;
}

struct node* join(struct node * root, struct node *root2, int x){
	struct node *temp=newNode(x);
	temp->left=root;
	temp->right=root2;

	return temp;
}

struct node* split(struct node *p, int x){
	if(p==NIL)
		return root;

	
	root2 = NIL;
    struct node *parent1 = NIL;
    struct node *parent2 = NIL;
    bool left;
    // Determine at which side of the root we will travel
    //boolean toLeft = root != null && k < root.data;
    if(root->key<x)
    	left=true;
    else
    	left=false;

    while (p != NIL && p->key!=x) {
        if(p->key < x && left){
        	while (p != NIL && p->key<x) {
	            parent1 = p;
	            p=p->right;

	        }
	        left=!left;
	        parent1->right=NIL;
        }
        else if(p->key>x && !left){
        	while (p != NIL && p->key>x) {
	            parent2 = p;
	            p=p->left;
	        }
	        left=!left;
	        parent2->left=NIL;
        }
        //setChild(parent1, toLeft, null); // Cut out the edge. root is now detached
        //toLeft = !toLeft; // toggle direction
        if(!left){
        	if (root2 == NIL) {
	            root2 = p; // This is the root of the other tree.
	        } else {
	            parent2->left=p;
	        }
	        p=p->left;
        }
        if(left){
        	parent1->right=p;
        	p=p->right;
        }
    }
    if(p->key==x){
    	parent1->right=p;
    	parent2->left=p->right;
    	parent1->right->right=NIL;
    }
    return root2;

/*

	while(t->key!=x && t!=NIL){

		if(t->key<x){
			if(t1==NIL){
				t1=t;
				t_1=t1;
			}
				
			else if(t1->right!=t){
				t1->right=t;
			}
			t1=t1->right;
			t=t->right;
		}
		if(t->key>x){
			if(t2==NIL)
				t2=t;
			else if(t2->left!=t){
				t2->left=t;
			}
			t2=t2->left;
			t=t->left;
		}
	}
	if(t->key==x){
		
	}
*/
	
}

int main(){
	NIL = (struct node*)malloc(sizeof(struct node));
	root=NIL;
	t_1=NIL;
	t_2=NIL;

	int ch;
	int x,quit=1;
	printf("\nFirst Tree :");
	while(quit!=0){
		
		printf("\n0: initialize,  1: insert,  2: traverse,  3: delete,  4: quit\n");
		printf("\n5: split,  6: 1st,  7: 2nd\n");
		printf("\nEnter you choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:
			scanf("%d",&x);
			root=initialize(root,x);
			break;
			case 1:
			scanf("%d",&x);
			insert(root,x,root);
			break;
			case 2:
			traverse(root,root);
			break;
			case 3:
			scanf("%d",&x);
			root=delete(root,x);
			break;
			case 5:
			scanf("%d",&x);
			root2=split(root,x);
			break;
			case 6:
			traverse(root,root);
			break;
			case 7:
			traverse(root2,root2);
			break;

			case 4:
			quit=0;
			break;
		}
		//printf("\nsize of structure: %d",sizeof(root));
	}

}