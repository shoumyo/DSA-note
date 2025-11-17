#include<iostream>
#include<climits>
using namespace std;

int main(){
    int array[]={1,2,3,4,5};
    int small=INT_MAX;
    int larger=INT_MIN;
    int s;
    int l;
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        if(small>array[i]){
            small=array[i];
            s=i;
        }
        if(larger<array[i]){
            larger=array[i];
            l=i;
        }
    }
    cout<<s+1<<endl;
    cout<<l+1<<endl;

    return 0;
}