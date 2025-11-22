#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<vector<int>>fourSum(vector<int>&num,int tar){
    vector<vector<int>>ans;
    int n=num.size();
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++){
        if(i>0 && num[i]==num[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j<n-1 && num[j]==num[j-1]){
                continue;
            }
            int p=j+1;
            int q=n-1;
            while(p<q){
                long long sum=(long long)num[i]+(long long)num[j]+(long long)num[p]+(long long)num[q];
                if(sum<tar){
                    p++;
                }
                else if(sum>tar){
                    q--;
                }
                else{
                    ans.push_back({num[i],num[j],num[p],num[q]});
                    p++;
                    q--;
                    while(p<q && num[p]==num[p-1]){
                        p++;
                    }
                }
            }
        }
        return ans;
    }
}

int main(){

    vector<int>num={-4,-3,-1,-2,-1,0,1,2,3,4};
    int tar=0;
     vector<vector<int>>ans=fourSum(num,tar);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}