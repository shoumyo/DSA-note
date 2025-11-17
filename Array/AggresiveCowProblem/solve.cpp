#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Assign C cows to N stall such that min distance them is largerst possible

bool isPossible(vector<int>&arr,int n,int c,int minAllow){
    int cow=1;
    int laststall=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-laststall>=minAllow){
            cow++;
            laststall=arr[i];
        }
        if(cow==c){
            return true;
        }
    }
    return false;
}

int solve(vector<int>&arr,int n,int c){
    sort(arr.begin(),arr.end());
    int st=1;
    int end=arr[n-1]-arr[0];
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isPossible(arr,n,c,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){

    vector<int>arr={1,2,8,4,9};
    int c=3;
    int n=5;

    cout<<solve(arr,n,c);

    return 0;
}