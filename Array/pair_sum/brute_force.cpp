#include<iostream>
#include<vector>
using namespace std;

vector<int>pairSum(vector<int>arr,int n,int target){
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

int main(){

    vector<int>arr={1,2,3,4,5};
    int target=9;

    vector<int>ans=pairSum(arr,5,target);
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}