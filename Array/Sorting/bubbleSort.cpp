#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void bubbleSort(vector<int> &arr,int n){     //Time complexity 0(n*n)
    for(int i=0;i<n-1;i++){
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

int main(){
    int n=5;
    vector<int> arr={4,1,5,2,3};

    bubbleSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<endl;
    }
}