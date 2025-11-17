#include<iostream>
using namespace std;

pair<int,int> linearSearch(int matrix[][3],int row,int col,int key){
    pair<int,int >ans={-1,-1};
    for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(matrix[i][j]==key){
                ans.first=i;
                ans.second=j;
				return ans;
			}
		}
	}
	return ans;
}

int main(){

    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int key=4;
    pair<int,int>ans=linearSearch(matrix,4,3,4);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}