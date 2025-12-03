#include<iostream>
using namespace std;
#include<vector>
#include<string>

void helper(vector<vector<int>>&mat,int row,int col,vector<string>&ans,string path){
    int n=mat.size();
    if(row<0 || col<0 || row>=n || col>=n || mat[row][col]<=0 ){
        return;
    }

    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }
    mat[row][col]=-1;
    //down
    helper(mat,row+1,col,ans,path+"D");
    //up
    helper(mat,row-1,col,ans,path+"U");
    //left
    helper(mat,row,col-1,ans,path+"L");
    //right
    helper(mat,row,col+1,ans,path+"R");

    mat[row][col]=1;
}

vector<string>findpath(vector<vector<int>>&mat){
    int n=mat.size();
    vector<string>ans;
    string path="";
    helper(mat,0,0,ans,path);
    return ans;
}

int main() {
    cout << "Test Case 1:" << endl;
    vector<vector<int>> mat1 = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    
    vector<string> result1 = findpath(mat1);
    if (result1.empty()) {
        cout << "No paths found!" << endl;
    } else {
        cout << "Paths found: " << result1.size() << endl;
        for (const string& path : result1) {
            cout << path << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest Case 2:" << endl;
    vector<vector<int>> mat2 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    vector<string> result2 = findpath(mat2);
    if (result2.empty()) {
        cout << "No paths found!" << endl;
    } else {
        cout << "Paths found: " << result2.size() << endl;
        for (const string& path : result2) {
            cout << path << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest Case 3 (No path):" << endl;
    vector<vector<int>> mat3 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    vector<string> result3 = findpath(mat3);
    if (result3.empty()) {
        cout << "No paths found!" << endl;
    } else {
        cout << "Paths found: " << result3.size() << endl;
        for (const string& path : result3) {
            cout << path << " ";
        }
        cout << endl;
    }
    
    return 0;
}