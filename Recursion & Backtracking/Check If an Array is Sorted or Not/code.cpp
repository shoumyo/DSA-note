#include<iostream>
using namespace std;
#include<vector>

bool isSorted(vector<int>arr,int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[n-1]<arr[n-2]){
        return false;
    }
    if(!isSorted(arr,n-1)){
        return false;
    }
    return true;
}

int main(){

    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    cout<<isSorted(arr,n);

    return 0;
}