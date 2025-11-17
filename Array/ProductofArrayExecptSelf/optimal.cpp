#include<iostream>
#include<vector>
using namespace std;

vector<int>productofArrayEceptSelf(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n,1);
    // vector<int>pre(n,1);
    // vector<int>suf(n,1);
    int suffix=1;

    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*arr[i-1];
    }
    for(int i=n-2;i>=0;i--){
        suffix=suffix*arr[i+1];
       ans[i]=suffix*ans[i];
    }
    // for(int i=0;i<n;i++){
    //     ans[i]=pre[i]*suf[i];
    // }
     
     return ans;
}

int main(){

    vector<int>arr={1,2,3,4};
    vector<int>ans=productofArrayEceptSelf(arr);
    for(int val:ans){
        cout<<val<<endl;
    }

    return 0;
}