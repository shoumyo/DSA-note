#include<iostream>
using namespace std;
#include<string>

bool isFreqSame(int freq[],int wfreq[]){
    for(int i=0;i<26;i++){
        if(freq[i]!=wfreq[i]){
            return false;
        }
    }
    return true;
}

bool check(string s1,string s2){
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        int idx=s1[i]-'a';
        freq[idx]++;
    }
    int win=s1.length();
    for(int i=0;i<s2.length();i++){
        int winidx=0,idx=i;
        int wfreq[26]={0};
        while(winidx<win && idx<s2.length()){
            wfreq[s2[idx]-'a']++;
            winidx++;
            idx++;
        }
        if(isFreqSame(freq,wfreq)){
            return true;
        }
    }
    return false;
}

int main(){

    string s2={"asdfasdfab"};
    string s1={"ac"};
    cout<<check(s1,s2)<<endl;

    return 0;
}