#include <stdio.h>
#include <stdlib.h>
int binarySearch(int a[],int key);
int n;
int main(int argc, char *argv[]) {
int i,key,res,a[50];
printf("Enter a size\n");
scanf("%d", &n);
printf("Enter elements in sorted order :\n");
for( i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("enter element to search:");
scanf("%d",&key);
 res=binarySearch(a,key);
 if(res!=0)
 printf("element found at index = %d",res);
 else
printf("element not found");
return 0;
}


int binarySearch(int a[],int key){
int l=0,h=n-1,mid;
while(l<=h){
mid= (l+h)/2;
if(key==a[mid]){
return mid;
}
else if(key<a[mid])
h=mid-1;
 else
 l=mid+1;
}
return 0;
}
