#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int>maxSlideWindow(vector<int>&nums,int k){
    deque<int>dq;
    vector<int>ans;

    for(int i=0;i<k;i++){
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<nums.size();i++){
        ans.push_back(nums[dq.front()]);

        while(dq.size()>0 && dq.front()<=i-k){
            dq.pop_back();
        }
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}

int main(){

    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;

    vector<int>ans=maxSlideWindow(nums,k);
    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}