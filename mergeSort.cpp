#include<iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end){
    int i=start;
    int j=mid+1;
    int k=0;
    int temp[end-start+1];
    
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(i=start;i<=end;i++){
    arr[i]=temp[i-start];
    }
}
void mergeSort(int *arr, int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}
int main(){
    int arr[5]={7, 1, 5, 3, 9};
    mergeSort(arr, 0, 4);
    
     for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}