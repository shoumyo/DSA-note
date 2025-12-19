#include<iostream>
using namespace std;
#include<vector>

int countInversios(vector<int>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){

    vector<int>arr={6,3,5,2,7};

    cout<<countInversios(arr)<<endl;

    return 0;
}