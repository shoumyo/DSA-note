#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>nextGreaterElement(vector<int>&num){
    int n=num.size();
    vector<int>ans(n,-1);
    stack<int>s;

    for(int i=2*n-1;i>=0;i--){
        while(s.size()>0 && num[s.top()]<=num[i%n]){
            s.pop();
        }
        ans[i%n]=s.empty()?-1:num[s.top()];
        s.push(i%n);
    }
    return ans;
}

int main(){

    vector<int>num={1,2,3,4,3};
    vector<int>res=nextGreaterElement(num);
    for(int val:res){
        cout<<val<<" ";
    }
    cout<<endl;

}