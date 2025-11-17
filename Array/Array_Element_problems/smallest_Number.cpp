#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int marks[5] = {1, 2, 3, 4, 5};
    int small = INT_MAX;
    for (int i = 0; i < sizeof(marks)/sizeof(int); i++)
    {
        // if (marks[i] < small)
        // {
        //     small = marks[i];
        // }
        small=min(small,marks[i]);
    }
    cout << small << endl;
    return 0;
}