#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void sorting(vector<int>&number,int n){
    int zero=0;
    int one=0;
    int two=0;
    for(int i=0;i<n;i++){
        if(number[i]==0){
            zero++;
        }
        else if(number[i]==1){
            one++;
        }
        else{
            two++;
        }
    }
    for(int i=1;i<=zero;i++){
        cout<<"0"<<endl;
    }
    for(int i=1;i<=one;i++){
        cout<<"1"<<endl;
    }
    for(int i=1;i<=two;i++){
        cout<<"2"<<endl;
    }
}

int main(){
    vector<int>number={2,0,2,1,1,0};
    int n=6;
    sorting(number,n);
    return 0;
}

//O(n)
