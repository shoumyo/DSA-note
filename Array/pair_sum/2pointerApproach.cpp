#include<iostream>
#include<vector>
using namespace std;

vector<int>pairSum(vector<int>nums,int target){
    vector<int>ans;
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j){
        int ps=nums[i]+nums[j];
        if(ps<target){
            i++;
        }
        else if(ps>target){
            j--;
        }
        else{
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }
    }
    return ans;
}

int main(){

    vector<int>nums={2,7,11,15};
    int target=26;
    vector<int>ans=pairSum(nums,target);
    cout<<ans[0]<<","<<ans[1]<<endl;

    return 0;
}