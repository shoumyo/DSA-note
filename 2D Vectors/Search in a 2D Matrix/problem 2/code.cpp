#include<iostream>
using namespace std;
#include<vector>

bool searchMatrix(vector<vector<int>>& matrix,int target){
    int n=matrix[0].size();
    int m=matrix.size();
    int r=0;
    int c=n-1;
    while(r<m && c>=0){
        if(target==matrix[r][c]){
            return true;
        }
        else if(target<matrix[r][c]){
            c--;
        }
        else{
            r++;
        }
    }
    return false;
}

int main(){

    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int target;
    cin>>target;
    if(searchMatrix(matrix,target)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    return 0;
}