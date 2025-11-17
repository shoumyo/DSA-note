#include <iostream>
#include <vector>
using namespace std;

void reverseVector(vector<int>&num){
    int st=0;
    int en=num.size()-1;
    while(st<en){
        swap(num[st],num[en]);
        st++;
        en--;
    }
}

int main()
{
    vector<int>num={1,2,3,4,5};
    reverseVector(num);
    for(int i:num){
        cout<<i<<" ";
    }
    return 0;
}