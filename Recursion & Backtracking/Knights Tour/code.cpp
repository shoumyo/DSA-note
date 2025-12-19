#include<iostream>
using namespace std;
#include<vector>

bool isvalid(vector<vector<int>>&grid,int r,int c,int n,int expVal){

    if(r<0 || c<0|| r>=n || c>=n || grid[r][c]!=expVal){
        return false;
    }
    if(expVal==n*n-1){
        return true;
    }
    int ans1=isvalid(grid,r-2,c+1,n,expVal+1);
    int ans2=isvalid(grid,r-1,c+2,n,expVal+1);
    int ans3=isvalid(grid,r+1,c+2,n,expVal+1);
    int ans4=isvalid(grid,r+2,c+1,n,expVal+1);
    int ans5=isvalid(grid,r+2,c-1,n,expVal+1);
    int ans6=isvalid(grid,r+1,c-2,n,expVal+1);
    int ans7=isvalid(grid,r-1,c-2,n,expVal+1);
    int ans8=isvalid(grid,r-2,c-1,n,expVal+1);

    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
}

bool validGrid(vector<vector<int>>&grid){
    return isvalid(grid,0,0,grid.size(),0);
}

int main(){
    // Test Case 1: Valid Knight's Tour (3x3 grid that should return false since Knight's Tour is impossible on 3x3)
    vector<vector<int>> grid1 = {
        {0, 5, 2},
        {7, 4, 1},
        {6, 3, 8}
    };
    
    cout << "Test Case 1 (3x3 grid): " << (validGrid(grid1) ? "Valid" : "Invalid") << endl;
    
    // Test Case 2: Valid Knight's Tour (5x5 grid example)
    vector<vector<int>> grid2 = {
        {0, 11, 16, 5, 20},
        {15, 4, 19, 10, 17},
        {22, 1, 12, 21, 6},
        {3, 14, 23, 18, 9},
        {24, 13, 2, 7, 8}
    };
    
    cout << "Test Case 2 (5x5 grid): " << (validGrid(grid2) ? "Valid" : "Invalid") << endl;
    
    // Test Case 3: Invalid Knight's Tour (5x5 grid with wrong sequence)
    vector<vector<int>> grid3 = {
        {0, 11, 16, 5, 20},
        {15, 4, 19, 10, 17},
        {22, 1, 12, 21, 6},
        {3, 14, 23, 18, 9},
        {24, 13, 2, 8, 7}  // Last two values swapped
    };
    
    cout << "Test Case 3 (Invalid 5x5): " << (validGrid(grid3) ? "Valid" : "Invalid") << endl;
    
    // Test Case 4: 4x4 grid (should be invalid since Knight's Tour doesn't exist on 4x4 starting from corner)
    vector<vector<int>> grid4 = {
        {0, 5, 10, 15},
        {11, 14, 1, 6},
        {4, 9, 12, 3},
        {13, 2, 7, 8}
    };
    
    cout << "Test Case 4 (4x4 grid): " << (validGrid(grid4) ? "Valid" : "Invalid") << endl;
    
    // Test Case 5: 1x1 grid (trivial case)
    vector<vector<int>> grid5 = {{0}};
    
    cout << "Test Case 5 (1x1 grid): " << (validGrid(grid5) ? "Valid" : "Invalid") << endl;
    
    return 0;
}