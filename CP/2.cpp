#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int size;
        cin>>size;
        string s;
        cin>>s;
        int a=0;
        for(int i=0;i<size;i=i+2){
            if((s[i]=='a'&& s[i+1]=='b')||(s[i]=='b'&& s[i+1]=='a')){
                a++;
            }
        }
        if(a!=0){
            cout<<a-1<<endl;
        }
        else{
            cout<<a<<endl;
        }
    }

    return 0;
}