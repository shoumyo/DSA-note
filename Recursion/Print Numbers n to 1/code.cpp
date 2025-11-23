#include<iostream>
using namespace std;

void printNumbers(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printNumbers(n-1);
}

int main(){

    int n;
    cin>>n;

    printNumbers(n);

    return 0;
}