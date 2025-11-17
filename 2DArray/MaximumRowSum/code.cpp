#include<iostream>
using namespace std;
#include<climits>

int getMaxSum(int mat[][3],int row,int col){
    int Maxsum=INT_MIN;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=mat[i][j];
        }
        Maxsum=max(Maxsum,sum);
    }
    return Maxsum;
}

int main(){

    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    cout<<getMaxSum(matrix,4,3)<<endl;

    return 0;
}