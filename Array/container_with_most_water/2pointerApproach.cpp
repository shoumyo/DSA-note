#include<iostream>
#include<vector>
using namespace std;

int mostWater(vector<int>&arr){
    int maxW=0;
    int st=0,en=arr.size()-1;
    while(st<en){
        int width=en-st;
        int height=min(arr[st],arr[en]);
        int curr=width*height;
        maxW=max(maxW,curr);
        arr[st]<arr[en]?st++:en--;
    }
    return maxW;
    //complexity O(N)
}

int main(){

    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<mostWater(height)<<endl;


    return 0;
}