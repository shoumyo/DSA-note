#include<iostream>
using namespace std;

int sumofArr(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans+=arr[i];
    }
    return ans;
}

int productofArr(int arr[],int size){
    int ans=1;
    for(int i=0;i<size;i++){
        ans*=arr[i];
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<sumofArr(arr,5)<<endl;
    cout<<productofArr(arr,5)<<endl;

    return 0;
}