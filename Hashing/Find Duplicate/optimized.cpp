#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

int findDuplicate(vector<int>&nums){
   int slow=nums[0];
   int fast=nums[0];
   do{
    slow=nums[slow];
    fast=nums[nums[fast]];
   }while(slow!=fast);

   slow=nums[0];
   while(slow!=fast){
    slow=nums[slow];
    fast=nums[fast];
   }
   return slow;
}

int main(){

    vector<int>nums={1,2,3,4,5,1};
    cout<<findDuplicate(nums);

    return 0;
}