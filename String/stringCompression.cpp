#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>

int compress(vector<char>& chars){
    int n=chars.size();
    int idx=0;
    for(int i=0;i<n;i++){
        char ch=chars[i];
        int count =0;
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx]=ch;
            idx++;
        }
        else{
            chars[idx]=ch;
            idx++;
            string str=to_string(count);
            for(auto dig:str){
                chars[idx]=dig;
                idx++;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}

int main(){

    vector<char> chars={'a','a','a','b','b','b'};
    int ans=compress(chars);
    for(int i=0;i<ans;i++){
        cout<<chars[i];
    }

    return 0;
}