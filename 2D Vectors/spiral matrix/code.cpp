#include <iostream>
using namespace std;
#include <vector>

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int srow = 0;
    int scol = 0;
    int erow = m - 1;
    int ecol = n - 1;
    vector<int> ans;

    while (srow <= erow && scol <= ecol)
    {
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(matrix[srow][j]);
        }
        for (int j = srow+1; j <= erow; j++)
        {
            ans.push_back(matrix[j][ecol]);
        }
        for (int j = ecol-1; j >= scol; j--)
        {
            if(srow==erow){
                break;
            }
            ans.push_back(matrix[erow][j]);
        }
        for (int j = erow-1; j >= srow + 1; j--)
        {
            if(scol==ecol){
                break;
            }
            ans.push_back(matrix[j][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (auto i : spiralOrder(matrix))
    {
        cout << i << " ";
    }

    return 0;
}