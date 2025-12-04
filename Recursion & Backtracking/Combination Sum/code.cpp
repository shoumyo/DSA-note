#include<iostream>
using namespace std;
#include<vector>
#include<set>

set<vector<int>>s;

void helper(vector<int>&arr,int idx,int target,vector<vector<int>>&ans, vector<int>&combination){
    if(idx==arr.size() || target<0){
        return;
    }
    if(target==0){
        if(s.find(combination)==s.end()){
            ans.push_back({combination});
            s.insert(combination);
        }
        return;
    }
    
    combination.push_back(arr[idx]);
    helper(arr,idx+1,target-arr[idx],ans,combination);
    helper(arr,idx,target-arr[idx],ans,combination);
    combination.pop_back();
    helper(arr,idx+1,target,ans,combination);
}

vector<vector<int>>combinationSum(vector<int>&arr,int target){
    vector<vector<int>>ans;
    vector<int>combination;
    helper(arr,0,target,ans,combination);
    return ans;
}

int main(){

     // Test case 1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    
    cout << "Test Case 1:" << endl;
    cout << "Candidates: [2, 3, 6, 7], Target: " << target1 << endl;
    vector<vector<int>> result1 = combinationSum(candidates1, target1);
    
    cout << "Combinations: " << endl;
    for (const auto& comb : result1) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Test case 2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    
    cout << "Test Case 2:" << endl;
    cout << "Candidates: [2, 3, 5], Target: " << target2 << endl;
    vector<vector<int>> result2 = combinationSum(candidates2, target2);
    
    cout << "Combinations: " << endl;
    for (const auto& comb : result2) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Test case 3: No combinations possible
    vector<int> candidates3 = {2, 4, 6};
    int target3 = 7;
    
    cout << "Test Case 3:" << endl;
    cout << "Candidates: [2, 4, 6], Target: " << target3 << endl;
    vector<vector<int>> result3 = combinationSum(candidates3, target3);
    
    if (result3.empty()) {
        cout << "No combinations found!" << endl;
    } else {
        cout << "Combinations: " << endl;
        for (const auto& comb : result3) {
            cout << "[";
            for (int i = 0; i < comb.size(); i++) {
                cout << comb[i];
                if (i < comb.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}