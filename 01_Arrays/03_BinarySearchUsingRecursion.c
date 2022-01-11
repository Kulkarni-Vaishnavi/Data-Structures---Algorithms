#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[] ,int key,int l,int h );
int n;
int main() {
int i,key,res,a[50];
int l,h;
printf("ENter a size\n");
scanf("%d", &n);
printf("Enter elements in sorted order :\n");
for( i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("enetr element to search:\n");
scanf("%d",&key);
l=0;
h=n-1;
 res = binarySearch(a, key, l, h);
 if (res != -1) 
 printf("\nNumber found at index %d", res);
 else
 printf("The number is not present in the list\n");
 return 0;
}
int binarySearch(int a[], int key, int l,int h){
 int mid;
if(l>h)
 return -1;
mid =(l+h)/2;
if(key==a[mid])
return (mid);
 else if(key<a[mid]){
binarySearch(a,key,l,mid-1);
}
else
binarySearch(a,key,mid+1,h);
}