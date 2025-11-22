#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

int subarraySum(vector<int>&num,int tar){
    int n=num.size();
    int count=0;
    vector<int>PS(n,0);
    PS[0]=num[0];

    for(int i=1;i<n;i++){
        PS[i]=PS[i-1]+num[i];
    }
    unordered_map<int,int>m;
    for(int j=0;j<n;j++){
        if(PS[j]==tar){
            count++;
        }
        int val=PS[j]-tar;
        if(m.find(val)!=m.end()){
            count+=m[val];
        }
        if(m.find(PS[j])==m.end()){
            m[PS[j]]=0;
        }
        m[PS[j]]++;
    }
    return count;
}

int main(){
    vector<int>num={9,4,20,3,10,5};
    int target=33;
    cout<<subarraySum(num,target);

    return 0;
}