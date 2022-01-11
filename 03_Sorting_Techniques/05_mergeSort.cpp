#include<iostream>
using namespace std;

void display(int a[],int size){

    for(int i = 0;i<size ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mergeSort(int a1[], int a2[], int a3[], int size1, int size2){
    int p,q,k;
    p=q=k=0;
    while((p <size1) && (q<size2)){

        if(a1[p] < a2[q]){
            a3[k++] = a1[p++];
        }
        else{
            a3[k++] = a2[q++];
        }
    }
    while(p<size1)
      a3[k++] = a1[p++];

    while(q<size2)
      a3[k++] = a2[q++];
}

int main(){

    int a1[] = {5, 8, 9, 28, 34};
    int a2[] = {4, 22, 25, 30, 33, 40, 42};
    int a3[12];

    int size1 = 5;
    int size2 = 7;
    
    mergeSort(a1,a2,a3,size1,size2);
    display(a3, 12);

    return 0;
}