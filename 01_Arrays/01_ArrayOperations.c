#include <stdio.h>
#include <stdlib.h>
void endadd(int a[]);
void startadd(int a[]);
void midadd(int a[]);
void deleteElement(int a[]);
void arrIndex(int a[]);
void search(int a[]);
void display(int a[],int n);
int n=0;
int main() {
	int i,one,ch;
	static int a[50];
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements of array:\n");
	for(i=0; i<n ; i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\nIf u want to preform another opertion click 1: ");
	scanf("%d",&one);
    while(1){
	if(one == 1){
	printf("\nArray Operations\n");
	printf("1. insert at starting position\n2. insert in middle\n3. insert at the end\n4. search an element\n5. delete an element\n6. Indexof\n7. exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: startadd(a);
		break;
		case 2:midadd(a);
		break;
		case 3: endadd(a);
		break;
		case 4: search(a);
		break;
		case 5: deleteElement(a);
		break;
		case 6: arrIndex(a);
		break;
		case 7: exit(0);
        }
	}
	else{
	 exit(0);
	break;
}
}
	return 0;
}

void endadd(int a[]){
	int pos;
	printf("Enter element to be insert: ");
	scanf("%d",&pos);
	a[n]=pos;
	n++;
	display(a,n);
	}
void startadd(int a[]) {
	int i,v;
	printf("enter the element to be added: ");
	scanf("%d",&v);
	for(i=n;i>0;i--){
	a[i] = a[i-1];
	}
	a[0]= v;
	n++;
	display(a,n);
}
void midadd(int a[]){
	int i,pos,x;
	printf("enter the position of the element: ");
	scanf("%d",&pos);
	printf("enter the element to be added: ");
	scanf("%d",&x);
        if(pos<=0|| pos>n+1)
           printf("invalid position");
        else{
	for(i=n;i>pos-1;i--)
		a[i]=a[i-1];
	a[pos-1]=x;
	n++;
	display(a,n);
    }
}
void deleteElement(int a[]) {
	int j,i;
	printf("enter element position\n");
	scanf("%d",&j);
	for(i=j-1;i<=n-1 ;i++)
		a[i]=a[i+1];
	n--;
	display(a,n);
}
void arrIndex(int a[]){
	 int num,i,index=0;
	 printf("Enter the element to know its index: ");
	 scanf("%d",&num);
	 for(i=0; i<n; i++){
	 	if(a[i]==num)
	 	  index=i;}
	 	printf("Index= %d",index);
}
void search(int a[]) {
		int flag,b,i;
	printf("enter element to be searched : ");
	scanf("%d",&b);
	for(i=0; i<n ; i++){
		if(a[i]==b){
			printf("element is found at index of : %d",i);
			flag++;
			break;
                      }
    }
    if(flag==0)
      printf("Element not found\n");
}
void display(int a[],int n){
        int i;
		printf("Elements of array are:\n ");
		for( i=0;i<n;i++)
		printf("%d ",a[i]);
	}
