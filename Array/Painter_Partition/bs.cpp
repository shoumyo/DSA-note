#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<int>&arr,int n,int m,int maxval){
    int painter=1;
    int time=0;
    for(int i=0;i<n;i++){
        if(time+arr[i]<=maxval){
            time+=arr[i];
        }
        else{
            painter++;
            time=arr[i];
        }
    }
    return painter<=m;
}

int painterspartition(vector<int>&arr,int n,int m){
    if(n<m){
        return -1;
    }
    int maxval=0;
    int ans=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxval=max(maxval,arr[i]);
    }
    int st=maxval;
    int en=sum;
    while(st<=en){
        int mid=st+(en-st)/2;
        if(isvalid(arr,n,m,mid)){
            ans=mid;
            en=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int>arr={40,30,10,20};
    int n=4,m=2;
    cout<<painterspartition(arr,n,m)<<endl;

    return 0;
}