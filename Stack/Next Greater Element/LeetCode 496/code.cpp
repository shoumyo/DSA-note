#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int>nextGreaterElement(vector<int>& nums1,vector<int>&nums2){
    unordered_map<int,int>m;
    stack<int>s;

    for(int i=nums2.size()-1;i>=0;i--){
        while(s.size()>0 && s.top()<=nums2[i]){
            s.pop();
        }
        if(s.empty()){
            m[nums2[i]]=-1;
        }
        else{
            m[nums2[i]]=s.top();
        }
        s.push(nums2[i]);
    }

    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}

int main() {
    // Test case 1
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    cout << "nums1: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums2) cout << num << " ";
    
    vector<int> result = nextGreaterElement(nums1, nums2);
    
    cout << "\nResult: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    // Test case 2
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};
    
    cout << "\nTest case 2:\n";
    cout << "nums1: ";
    for (int num : nums1_2) cout << num << " ";
    cout << "\nnums2: ";
    for (int num : nums2_2) cout << num << " ";
    
    result = nextGreaterElement(nums1_2, nums2_2);
    
    cout << "\nResult: ";
    for (int num : result) cout << num << " ";
    cout << endl;
    
    return 0;
}