#include<iostream>
#include<vector>
using namespace std;

int mostWater(int arr[]){
    int maxwatar=0;
    for(int i=0;i<9;i++){
         for(int j=i+1;j<9;j++){
            int width=j-1;
            int height=min(arr[j],arr[i]);
            maxwatar=max(maxwatar,(width*height));
         }
    }
    return maxwatar;
}

int main(){

    int height[]={1,8,6,2,5,4,8,3,7};
    cout<<mostWater(height)<<endl;

    return 0;
}