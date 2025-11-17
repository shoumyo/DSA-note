#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>arr1={3,4,5,6,7,0,1,2};
    int target=0;
    int st=0,end=arr1.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr1[mid]==target){
            cout<<mid+1<<endl;
            return 0;
        }
        if(arr1[st]<=arr1[mid]){
            if(arr1[st]<=target && target<=arr1[mid]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            if(arr1[mid]<=target && target<=arr1[end]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}