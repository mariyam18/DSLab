/*Description: Implementation of Binary Search Tree.
 Learner: Shaikh Mariyam Anis.
 */
 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int split(int arr[],int lower,int upper)
{
	int pivot = lower;
	int a=pivot+1;
	int b=upper,temp;
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[pivot];
	arr[pivot]=temp;
	return b;
}

	
void Quick_sort(int arr[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
		i=split(arr,lower,upper);
		Quick_sort(arr,lower,i-1);
		Quick_sort(arr,i+1,upper);
	}
}

int main()
{
   int n,i;
	int arr[MAX_SIZE];
	printf("Enter the no. of element:");
	scanf("%d",&n);
	printf("Enter the Element\n");
	for(i=0;i<n;i++)
	{
      scanf("%d",&arr[i]);
    }
	 Quick_sort(arr,0,n-1);
	 printf("Sorted array is\n");
	 for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	 
	return 0;
}

/*Output
 Enter the no. of element:5
Enter the Element
98
72
61
43
31
Sorted array is
31
43
61
72
98


------------------
(program exited with code: 0)
Press return to continue
*/

