#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximunSubarraySum(int arr[],int n){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=arr[j];
            maxSum=max(maxSum,currSum);
        }
    }
    return maxSum;
}

int main(){

    int arr[]={1,2,3,4,5,6,7,8};
    cout<<maximunSubarraySum(arr,8)<<endl;

    return 0;
}