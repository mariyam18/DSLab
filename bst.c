/*Description: Implementation of Binary Search Tree.
 Learner: Shaikh Mariyam Anis.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void insert(node**r,int num)
{
	node *temp,*ptr;
	temp=*r;
	if(temp==NULL)	
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else
	{
		if(num > temp->data)
			insert(&temp->right,num);
		else
			{
				insert(&temp->left,num);
			}			
		}
}
		

void traverse_inorder(node*q)
{
	if(q!=NULL)
	{
		traverse_inorder(q->left);
		printf("%d\t",q->data);
		traverse_inorder(q->right);			
	}
}

int search_bst(node*q,int num)
{
	if(q==NULL)	
		return 0;
	else
	{
		if(q->data==num)
				return 1;
		else
		{
			if(num > q->data){
				search_bst(q->right,num);
			}	
			else
			{
				search_bst(q->left,num);
			}			
		}
	}
}


void search_node(node **x,node*root,node**parent,int num,int*f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
    while(temp!=NULL)
	{
		if(temp->data==num)
	  {
		*f=1;
		*x=temp;
		return;
	  }
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
				
}





	
void delete(node**r,int num)
{
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;
	x=NULL;xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
	
	if(f==0)	
	{
		printf("\n The given no. is not found");
		return;
	}
	
	if(x->left==NULL && x->right==NULL)			   //x has no child
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	 else if(x->left!=NULL && x->right==NULL)			//x has left child
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
	else if (x->left==NULL && x->right!=NULL)			//x has right child
	{
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
	else if (x->left!=NULL && x->right!=NULL)			//x has both child
	{
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(xsucc->data > parent->data)
			parent->right=NULL
			;
		else
			parent->left=NULL;
		x->data=xsucc->data;
		x=xsucc;
	}
	free(x);
}	
		
		
		



 
int main()
{
	node*root;
	root=NULL;
	insert(&root,20);
	insert(&root,15);
	insert(&root,13); 
	insert(&root,17);
	insert(&root,16);
	insert(&root,19);
	insert(&root,18);
	insert(&root,25);		
    traverse_inorder(root);
    if(search_bst(root,9)==1)
    {
		printf("\n the %d is present",9);
	}
	else
	    printf("\n not found");
	    delet(&root,25);
    return 0;
}    
