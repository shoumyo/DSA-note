#include<iostream>
#include<vector>
using namespace std;

vector<int>productofArrayEceptSelf(vector<int>arr){
    vector<int>ans;
     for(int i=0;i<arr.size();i++){
        int product=1;
        for(int j=0;j<arr.size();j++){
            if(i!=j){
                product*=arr[j];
            }
        }
        ans.push_back(product);
     }
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