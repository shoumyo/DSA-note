#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b){
            if(a%b==0){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        else{
            if(a==b){
                cout<<0<<endl;
            }
            else if(b%a==0){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }

    return 0;
}