#include<iostream>
using namespace std;
#include<vector>

int rBS(vector<int>arr,int target,int start,int end){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            rBS(arr,target,mid+1,end);
        }
        else{
            rBS(arr,target,start,mid+1);
        }
    }
    return -1;
}

int main(){

    vector<int>arr={1,2,3,4,5,6,7,8};
    int target=5;

    cout<<rBS(arr,target,0,arr.size())+1<<endl;

    return 0;
}