#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull(){
//returns 1 if stack is full else returns -1
 return top==MAX_SIZE-1;
 
}

int isEmpty(){
//returns 1 if stack is empty else returns -1
return top==-1;

}

int peek(){
//return element at the top of stack
 return stack[top];
}

void push(int e){
//inserts an element into stack
if (!isFull())
{
	top++;
	int e;
	stack[top]=e;
	printf(" element e is successfully inserted");
}
else{
	printf("stack overflow\n");
	
}
}

void pop(){
//delets element from stack	
int d;
if(!isEmpty())	
{
	d= stack[top];
	top--;
	printf("msg element %d successfully deleted",d);
}
else{
	printf("msg stack underflow");
}			
}

int main()
{
	int choice,e;
	do
	{
		printf ("\t\t\tMENU \n1.peek \n2.push \n3.pop \n4.exit\n");
         printf("\n Enter  your choice\n");
         scanf("%d",&choice);
		//take input in choice variable
		switch(choice)
		{
			case 1:
			e=peek(stack);
			printf("%d",e);    //call peek function
			break;
			
			case 2:
			printf("\n enter the element\n");
			scanf("%d",&e);
			push(e);   //call push function
			break;
			
		    case 3:
		    pop(stack);  //call pop function
			break;
			
		    case 4:
		    return(0);   //call exit(0) function
			break;
			
			default:
			printf("\n invalid choice\n");
			break;
	}
  }while(1);
   return 0;
}				
		
		
