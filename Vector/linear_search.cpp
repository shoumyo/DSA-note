#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>num,int target){
    for(int i=0;num.size();i++){
        if(num[i]==target){
            return i+1;
        }
    }
    return -1;
}

int main(){

    vector<int>num={1,2,3,4,5};
    int target;
    cin>>target;

    cout<<linearSearch(num,target)<<endl;

    return 0;
}