#include<stdio.h>
#include<math.h>

#define MAX_SIZE 20
 
 int hash(int k){
	 return k%MAX_SIZE;
 }
 
 int collision_res(int h) {
	 return ++h%MAX_SIZE;
 }

 int quad_probe(int h,int i){
			return (int)(h+pow(i,2))%MAX_SIZE;
}

int double_hash(int h,int i){
	return (h+i*collision_res(h)%MAX_SIZE);
}

 void display(int a[])
		{
			int i;
			printf("elements of the array are\n");
			for(i=0;i<MAX_SIZE;i++)
			printf("%d\t",a[i]);
		}
 int main(){
	 int a[MAX_SIZE],i,h,e,count,ch;
	 for(i=0;i<MAX_SIZE;i++)
	 a[i]=-1;
	 do
	 {
		 count=0;
		 printf("enter the element to be store");
		 scanf("%d",&e);
		 h=hash(e);
		 if(a[h]==-1){
		 a[h]=e;
		 display(a);
	 }
		 else{
				while(count<MAX_SIZE){
					 count++;
					 printf("collision occured at %d",h);
					 printf("please enter your choice for resoulution");
					 printf("\n1.linear probing\n2.quadratic probing\n3.double hashing\n");
					 scanf("%d",&ch);
					 switch(ch){
						 case 1:
						 h=collision_res(h);
						 break;
						 case 2: 
						 h=quad_probe(h,i);
						 break;
						 case 3:
						 h=double_hash(h,i);
						 break;
						 default:
						 printf("invalid chaoice");
						 count--;
						 break;
					 }
					  h=collision_res(h);
			 if(a[h]==-1)
			 {
			 a[h]=e;
			 display(a);
			 break;
		 }
		 }
	 }
		 if(count==MAX_SIZE)
		 {
		 printf("\nthe array is full");
		 return 0;
	 }
	 }while(1);
 }



/*Output
  Enter the Number to be stored=
25
Element of Array are...
-1	-1	-1	-1	-1	25	-1	-1	-1	-1	 
  
Enter the Number to be stored=
21
Element of Array are...
-1	21	-1	-1	-1	25	-1	-1	-1	-1	
  
Enter the Number to be stored=
23
Element of Array are...
-1	21	-1	23	-1	25	-1	-1	-1	-1	
 
Enter the Number to be stored=
45
collision occured at 5
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
-1	21	45	23	-1	25	-1	-1	-1	-1	
  
Enter the Number to be stored=
89
Element of Array are...
-1	21	45	23	-1	25	-1	-1	-1	89	 
 
Enter the Number to be stored=
87
Element of Array are...
-1	21	45	23	-1	25	-1	87	-1	89	
  
Enter the Number to be stored=
54
Element of Array are...
-1	21	45	23	54	25	-1	87	-1	89	 
 
Enter the Number to be stored=
62
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
Element of Array are...
-1	21	45	23	54	25	-1	87	62	89	
  
Enter the Number to be stored=
2
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
2	21	45	23	54	25	-1	87	62	89	
 
 Enter the Number to be stored=
12
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 5
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
2	21	45	23	54	25	12	87	62	89	 
* 
Enter the Number to be stored=
21
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2 
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 0
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2 
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
 Array is Full or collision Resolution not successful
------------------
(program exited with code: 0)
Press return to continue
*/		      
		
