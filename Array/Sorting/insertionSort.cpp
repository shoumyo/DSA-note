#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void insertionSort(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

int main(){
    int n=5;
    vector<int> arr={4,1,5,2,3};

    insertionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }
}