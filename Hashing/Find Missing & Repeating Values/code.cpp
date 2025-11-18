#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

vector<int>find(vector<vector<int>>&grid){
    vector<int>ans;
    unordered_set<int>s;
    int n=grid.size();
    int a,b;

    // b = expSum + a - actualSum

    int expSum=0;
    int actualSum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actualSum+=grid[i][j];
            if(s.find(grid[i][j])!=s.end()){
                a=grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expSum=(n*n)*(n*n+1)/2;
    b=expSum + a - actualSum;
    ans.push_back(b);
    return ans;
}

int main(){

    vector<vector<int>>grid={{1,2,3},{4,9,6},{7,8,9}};
    for(auto i:find(grid)){
        cout<<i<<" ";
    }

    return 0;
}