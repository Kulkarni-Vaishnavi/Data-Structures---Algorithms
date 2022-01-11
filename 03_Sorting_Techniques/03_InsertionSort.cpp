#include<iostream>
using namespace std;

void display(int a[],int size){

    for(int i = 0;i<size ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int a[],int size){
    int j;
    for(int i=1; i<size; i++){

        int k = a[i];
        for(j=i-1; j>=0 && k<a[j]; j--)
        {
          a[j+1] = a[j];
        }
        a[j+1] = k;
        
    }
}

int main(){

    int a[] = {40, 20, 50, 60, 30, 10};
    int size = 6;

    cout<<"list before sorting"<<endl;
    display(a,size);
    insertionSort(a,size);
    cout<<"list after sorting"<<endl;
    display(a,size);


}