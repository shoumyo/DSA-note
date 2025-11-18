#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

int findDuplicate(vector<int>&nums){
    unordered_set<int>s;

    for(auto val:nums){
        if(s.find(val)!=s.end()){
            return val;
        }
        s.insert(val);
    }
    return -1;
}

int main(){

    vector<int>nums={1,2,3,4,5,1};
    cout<<findDuplicate(nums);

    return 0;
}