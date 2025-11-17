#include<iostream>
#include<climits>
using namespace std;

int MaxNum(int arr[],int size){
    int index=0;
    int Max=arr[0];
    for(int i=1;i<size;i++){
        if(Max<arr[i]){
            Max=arr[i];
            index=i;
        }
    }
    return index;
}

int MinNum(int arr[],int size){
    int index=0;
    int MIN=arr[0];
    for(int i=1;i<size;i++){
        if(MIN>arr[i]){
            MIN=arr[i];;
            index=i;
        }
    }
    return index;
}

int main(){
    int arr[]={1,2,3,4,5};
    swap(arr[MaxNum(arr,5)],arr[MinNum(arr,5)]);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}