#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

void reverseString(vector<char>&s){
    int st=0;
    int en=s.size()-1;
    while(st<en){
        swap(s[st++],s[en--]);
    }
}

int main(){

    vector<char>s={'h','e','l','l','o'};
    reverseString(s);
    for(auto val :s){
        cout<<val<<" "<<endl;
    }

    string s1={"shoumyo"};
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;

    return 0;
}