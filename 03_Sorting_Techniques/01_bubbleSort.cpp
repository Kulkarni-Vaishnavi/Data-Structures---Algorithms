#include<iostream>
using namespace std;

void display(int a[],int size){

    for(int i = 0;i<size ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int a[], int size){

    for(int i=0; i<size-1; i++){

        int xchanges =0;
        for(int j=0; j<size-1-i; j++){

            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                xchanges ++;
            }
        }
        if(xchanges == 0){ // if list is sorted
           cout<<"List is sorted"<<endl;
           break;
        }
    }
}

int main(){

    int a[] = {40, 20, 50, 60, 30, 10};
    int size = 6;

    cout<<"list before sorting"<<endl;
    display(a,size);
    bubbleSort(a,size);
    cout<<"list after sorting"<<endl;
    display(a,size);


}
