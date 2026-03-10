#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int trapW(vector<int>&heigh){
    int n=heigh.size();
    int ans=0;
    int l=0,r=n-1;
    int lmax=0,rmax=0;
    while(l<r){
        lmax=max(lmax,heigh[l]);
        rmax=max(rmax,heigh[r]);
        if(lmax<rmax){
            ans+=lmax-heigh[l];
            l++;
        }
        else{
            ans+=rmax-heigh[r];
            r--;
        }
    }
    return ans;
}

int main(){

    vector<int>height{4,2,0,3,2,5};
    cout<<trapW(height)<<endl;

    return 0;
}