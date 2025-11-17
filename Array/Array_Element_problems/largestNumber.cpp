#include <iostream>
#include<climits>
using namespace std;

int main()
{
    int marks[5] = {1, 2, 3, 4, 5};
    int large = INT_MIN;
    for (int i = 0; i < sizeof(marks) / sizeof(int); i++)
    {
        // if (marks[i] > large)
        // {
        //    large = marks[i];
        // }
        large = max(large, marks[i]);
    }
    cout << large << endl;
    return 0;
}