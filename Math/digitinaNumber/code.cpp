#include<iostream>
using namespace std;

void printDigitsCount(int n){
    int count=0;
    while(n!=0){
        int digit=n%10;
        count++;
        n=n/10;
    }
    cout<<count<<endl;
}

int main(){

    printDigitsCount(1234);

    return 0;
}