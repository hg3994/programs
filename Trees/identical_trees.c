#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//Check whether two trees are identical or not? 

struct node{
	int data;
	struct node* left;
	struct node* right;
};

//(struct node*) is the return type of this function "newnode"
struct node* newnode(int data){
	struct node* node= (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int compare(struct node* a, struct node* b){
	    /*1. both empty */
    	if (a==NULL && b==NULL)
        	return 1;
 
    /* 2. both non-empty -> compare them */
    	if (a!=NULL && b!=NULL)
    	{
        	return
        	(
        	    a->data == b->data &&
        	    compare(a->left, b->left) &&
        	    compare(a->right, b->right)
        	);
    	}
     
    /* 3. one empty, one not -> false */
    	return 0;
}

int main(){
	int x;
	//printf("1\n");
	struct node *root1= newnode(1);
	root1->left= newnode(2);
	root1->right=newnode(3);
	root1->left->left= newnode(4);
	root1->left->right= newnode(5);
	
	struct node *root2= newnode(1);
	root2->left= newnode(2);
	root2->right=newnode(3);
	root2->left->left= newnode(4);
	root2->left->right= newnode(5);
	//printf("2\n");
	if(compare(root1, root2))
    		printf("Both tree are identical.\n");
    	else
        	printf("Trees are not identical.\n");
	return 0;
}
