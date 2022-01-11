#include<iostream>
using namespace std;

void display(int a[],int size){

    for(int i = 0;i<size ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int partition(int a[], int low, int high){
    int i,j,pivot,temp;
    i = low+1;
    j = high;
    pivot = a[low];

    while(i<=j){
        while((a[i] < pivot) && (i<high))
           i++;
        while(a[j] > pivot)
          j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j]= temp;
            i++;
            j--;
        }
        else{
            i++;
        }

        
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;

}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){

    int a[] = {40, 20, 50, 60, 30, 10};
    int size = 6;

    cout<<"list before sorting"<<endl;
    display(a,size);
    quickSort(a,0,size-1);
    cout<<"list after sorting"<<endl;
    display(a,size);


}