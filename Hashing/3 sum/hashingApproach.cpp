#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>

vector<vector<int>>threeSum(vector<int>&num){
    int n=num.size();
    set<vector<int>>triplates;    //to store unique triplattes
    for(int i=0;i<n;i++){
        int tar=-num[i];
        set<int>s;
        for(int j=i+1;j<n;j++){
            int tofind=tar-num[j];
            if(s.find(tofind)!=s.end()){
                vector<int>tri={num[i],num[j],tofind};
                sort(tri.begin(),tri.end());
                triplates.insert(tri);
            }
            s.insert(num[j]);
        }
    }
    vector<vector<int>>ans(triplates.begin(),triplates.end());
    return ans;
}

int main(){

    vector<int>num={-1,0,1,2,-1};
    vector<vector<int>>ans=threeSum(num);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}