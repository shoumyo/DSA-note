#include<iostream>
using namespace std;
#include<vector>

int subarraySum(vector<int>&num,int tar){
    int n=num.size();
    int count=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=num[j];
            if(sum==tar){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int>num={9,4,20,3,10,5};
    int target=33;
    cout<<subarraySum(num,target);

    return 0;
}