#include<iostream>
using namespace std;
#include<vector>

bool isSafe(vector<vector<char>>&board,int row,int col,char dig){
    for(int j=0;j<9;j++){
        if(board[row][j]==dig){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(board[j][col]==dig){
            return false;
        }
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;

    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>>&board,int row,int col){
    if(row==9){
        return true;
    }
    int nextR=row;
    int nextC=col+1;
    if(nextC==9){
        nextR=row+1;
        nextC=0;
    }
    if(board[row][col]!='.'){
        return helper(board,nextR,nextC);
    }
    for(char i='1';i<='9';i++){
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(helper(board,nextR,nextC)){
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>&board){
    helper(board,0,0);
}

void printBoard(vector<vector<char>>& board) {
    cout << "\nSolved Sudoku:\n";
    cout << "-------------------\n";
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0 && i != 0) {
            cout << "-------------------\n";
        }
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------\n";
}

int main(){
    // Example Sudoku puzzle (0 represents empty cells, but we'll use '.')
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Original Sudoku Puzzle:\n";
    printBoard(board);

    // Solve the Sudoku
    solveSudoku(board);

    // Print the solved Sudoku
    printBoard(board);

    // Test with another puzzle
    cout << "\n\nTesting with another puzzle:\n";
    
    vector<vector<char>> board2 = {
        {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'}
    };

    cout << "\nSecond Sudoku Puzzle:\n";
    printBoard(board2);

    solveSudoku(board2);
    
    cout << "\nSolved Second Sudoku:\n";
    printBoard(board2);

    return 0;
}