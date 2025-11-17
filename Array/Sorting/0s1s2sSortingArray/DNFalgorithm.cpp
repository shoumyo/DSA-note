#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void DNFsorting(vector<int>&number,int n){
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(number[mid]==0){
            swap(number[low],number[mid]);
            low++;
            mid++;
        }
        else if(number[mid]==1){
            mid++;
        }
        else{
            swap(number[high],number[mid]);
            high--;
        }
    }
}

int main(){
    vector<int>number={2,0,2,1,1,0};
    int n=6;
    DNFsorting(number,n);
    for(int i=0;i<n;i++){
        cout<<number[i]<<endl;
    }
    return 0;
}
