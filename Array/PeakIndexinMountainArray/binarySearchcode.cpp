#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={0,1,2,3,4,9,8,7,6};
    int st=1;
    int end=arr.size()-2;
   
    while(st<=end){
         int mid=st+(end-st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            cout<<mid+1<<endl;
            return 0;
        }
        else if(arr[mid-1]<arr[mid]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<-1<<endl;

    return 0;
}