#include<iostream>
using namespace std;

bool isArmstrong(int n){
    int copyN=n;
    int sumcube=0;
    while(n!=0){
        int dig=n%10;
        sumcube+=(dig*dig*dig);
        n/=10;
    }
    return sumcube=copyN;
}

int main(){

    int n=153;
    if(isArmstrong(n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}