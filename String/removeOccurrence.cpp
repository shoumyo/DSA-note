#include<iostream>
#include<string>
using namespace std;

string removeO(string s,string part){
    while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){

    string s={"daabcbaabcbc"};
    cout<<removeO(s,"abc")<<endl;

    return 0;
}