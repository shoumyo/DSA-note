#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(){
    vector<int>number={2,0,2,1,1,0};
    int n=6;
    sort(number.begin(),number.end());
    for(int i=0;i<n;i++){
        cout<<number[i]<<endl;
    }
    return 0;
}

// O(nlogn)