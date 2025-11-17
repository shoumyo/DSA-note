#include<iostream>
using namespace std;

int main(){

    int arr[]={1,4,3,4,5};
    for(int i=0;i<5;i++){
        bool check=true;
        for(int j=0;j<5;j++){
            if(i!=j && arr[i]==arr[j]){
                check=false;
                break;
            }
        }
        if(check==true){
            cout<<arr[i]<<" ";
        }
    }

    return 0;
}