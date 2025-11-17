#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int st, int end)
{
    if (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (target > arr[mid])
        {
            return binarySearch(arr, target, mid + 1, end);
        }
        else if (target < arr[mid])
        {
            return binarySearch(arr, target, st, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{

    vector<int> arr1 = {-1, 0, 3, 5, 9, 12};
    int target = 12;
    int st = 0;
    int end = arr1.size() - 1;
    cout << binarySearch(arr1, target, st, end) + 1 << endl;

    return 0;
}