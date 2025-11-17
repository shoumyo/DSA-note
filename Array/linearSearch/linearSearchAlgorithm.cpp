#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i+1;
        }
    }
    return -1;
}

int main(){

    int arr[]={1,2,3,4,5};
    int target;
    cin>>target;
    cout<<linearSearch(arr,5,target)<<endl;

    return 0;
}
