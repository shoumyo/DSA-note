#include<iostream>
using namespace std;
#include<vector>

int partition(vector<int>&arr,int st,int end){
    int idx=st-1;
    int pivot=arr[end];

    for(int i=st;i<end;i++){
        if(arr[i]<=pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void quickSort(vector<int>&arr,int st,int end){
    if(st<end){
        int pivIdx=partition(arr,st,end);
        quickSort(arr,st,pivIdx-1);
        quickSort(arr,pivIdx+1,end);
    }
}

int main(){

    vector<int>arr={12,31,35,8,32,17};
    quickSort(arr,0,arr.size()-1);
    for(auto i :arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}