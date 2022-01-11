#include<iostream>
using namespace std;

void display(int a[],int size){

    for(int i = 0;i<size ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int a[], int size){
    
    int min,j ;
    for(int i=0; i<size-1; i++){
        min =i;
        for( j=i+1; j<size; j++){

            if(a[min] > a[j])
              min =j;
        }
        if(i!= min){
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        }
    }
}

int main(){

    int a[] = {40, 20, 50, 60, 30, 10};
    int size = 6;

    cout<<"list before sorting"<<endl;
    display(a,size);
    selectionSort(a,size);
    cout<<"list after sorting"<<endl;
    display(a,size);


}