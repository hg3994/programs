#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void doubleTree(struct node* node)
{
 	 struct node* oldLeft;
 
 	 if (node==NULL) return;
 	
	  /* do the subtrees */
	  doubleTree(node->left);
	  doubleTree(node->right);
 
	  /* duplicate this node to its left */	
	  oldLeft = node->left;
	  node->left = newNode(node->data);
  	node->left->left = oldLeft;
}

void printinorder(struct node* node)
{
	if(node==NULL)
		return;
	else
	{
		printinorder(node->left);
		printf("%d\t",node->data);
		printinorder(node->right);
	}
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  printinorder(root);
  doubletree(root);
  printf("\n");
  printinorder(root);
  return 0;
}
