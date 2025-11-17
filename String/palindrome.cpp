#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

bool palindrome(string s){
    int st=0;
    int en=s.length()-1;
    while(st<en){
        if(!isalpha(s[st])){
            st++;
            continue;
        }
        if(!isalpha(s[en])){
            en--;
            continue;
        }
        if(tolower(s[st]!=tolower(s[en]))){
            return false;
        }
        st++;
        en--;
    }
    return true;
}


int main(){

    string s={"asdtdsa"};
    cout<<palindrome(s)<<endl;

    return 0;
}