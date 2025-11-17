#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void mergeSorted(vector<int>&A,vector<int>&B,int n,int m){
    int idx=n+m-1;
    int i=n-1;
    int j=m-1;
    while(i>=0 && j>=0){
        if(A[i]>B[j]){
            A[idx]=A[i];
            i--;
            idx--;
        }
        else{
            A[idx]=B[j];
            j--;
            idx--;
        }
    }
    while(j>=0){
        A[idx]=B[j];
        j--;
        idx--;
    }
}

int main(){
    vector<int> A={1,2,3,0,0,0};
    vector<int>B={2,5,6};
    int n=3;
    int m=3;

    mergeSorted(A,B,n,m);

    for(int i=0;i<n+m;i++){
        cout<<A[i]<<" "<<endl;
    }
}