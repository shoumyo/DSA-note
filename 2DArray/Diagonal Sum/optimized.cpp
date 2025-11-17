#include<iostream>
using namespace std;

int diagonalSum(int matrix[][3],int n){
    int ans=0;
    for(int i=0;i<n;i++){
       ans+=matrix[i][i];
       if(i!=n-1-i){
        ans+=matrix[i][n-i-1];
       }
    }
    return ans;
}

int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    cout<<diagonalSum(matrix,n)<<endl;
    return 0;
}