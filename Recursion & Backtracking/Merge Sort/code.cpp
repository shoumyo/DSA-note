#include<iostream>
using namespace std;
#include<vector>

void merge(vector<int>&arr,int st,int mid,int en){
    vector<int>temp;
    int i=st;int j=mid+1;
    while(i<=mid && j<=en){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=en){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[st+i]=temp[i];
    }
}

void mergeSort(vector<int>&arr,int st,int en){
    if (st<en)
    {
        int mid=st+(en-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,en);
        merge(arr,st,mid,en);
    }
    
}

int main(){

    vector<int>arr={12,31,35,8,32,17};

    mergeSort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}