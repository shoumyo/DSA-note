#include<iostream>
using namespace std;
#include<vector>

void printSubset(vector<int>&arr,vector<int>&ans,int i){
    if(i==arr.size()){
        for(int val :ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return ;
    }

    ans.push_back(arr[i]);
    printSubset(arr,ans,i+1);

    ans.pop_back();

    int idx=i+1;

    while(idx<arr.size() && arr[idx]==arr[idx-1]){
        idx++;
    }
    printSubset(arr,ans,idx);
}

int main(){

    vector<int>arr={1,2,2};
    vector<int>ans;

    printSubset(arr,ans,0);

    return 0;
}