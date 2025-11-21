#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>

vector<vector<int>>threeSum(vector<int>&num){
    int n=num.size();
    vector<vector<int>>ans;
    set<vector<int>>s;    //to store unique triplattes
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(num[i]+num[j]+num[k]==0){
                    vector<int>trip={num[i],num[j],num[k]};
                    sort(trip.begin(),trip.end());

                    if(s.find(trip)==s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
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