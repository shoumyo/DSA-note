#include<iostream>
using namespace std;
#include<vector>

void getP(vector<int>&nums,int idx,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back({nums});
        return;
    }
    
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        getP(nums,idx+1,ans);

        swap(nums[idx],nums[i]);
    }
}

vector<vector<int>>permutation(vector<int>&num){
    vector<vector<int>>ans;
    getP(num,0,ans);
    return ans;
}

int main(){

    vector<int>arr={1,2,3};
    for(auto &i:permutation(arr)){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}