#include<iostream>
using namespace std;
#include<vector>

bool searchinRow(vector<vector<int>>& matrix,int target,int midR){
    int n=matrix[0].size();
    int st=0;
    int en=n-1;
    while(st<=en){
        int mid=st+(en-st)/2;
        if(matrix[midR][mid]==target){
            return true;
        }
        else if(matrix[midR][mid]<target){
            st=mid+1;
        }
        else{
            en=mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int stR=0,enR=m-1;
    while(stR<=enR){
        int midR=stR+(enR-stR)/2;
        if(target>=matrix[midR][0] && target<=matrix[midR][n-1]){
            return searchinRow(matrix,target,midR);
        }
        else if(target>matrix[midR][n-1]){
            stR=midR+1;
        }
        else{
            enR=midR-1;
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