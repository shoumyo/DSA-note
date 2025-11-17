#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void selectionSort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int sI=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[sI]){
                sI=j;
            }
        }
        swap(arr[i],arr[sI]);
    }
}

int main(){
    int n=5;
    vector<int> arr={4,1,5,2,3};

    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}