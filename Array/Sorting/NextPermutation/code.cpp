#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

int main(){
    vector<int>A={1,2,3,6,5,4};
    int n=6;
    int piv=-1;
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            piv=i;
            break;
        }
    }
    if(piv==-1){
        sort(A.begin(),A.end());
    }
    for(int i=n-1;i>piv;i--){
        if(A[i]>A[piv]){
            swap(A[i],A[piv]);
            break;
        }
    }
    int i=piv+1;
    int j=n-1;
    while(i<=j){
        swap(A[i],A[j]);
        i++;
        j--;
    }

    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }

    return 0;
}