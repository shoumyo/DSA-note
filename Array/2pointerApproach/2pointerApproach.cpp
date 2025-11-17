#include <iostream>
using namespace std;

// swapping an arrary using 2 pointer approach

void pointer2Apporach(int arr[], int size)
{
    int st = 0;
    int en = size - 1;
    while (st < en)
    {
        swap(arr[st], arr[en]);
        st++;
        en--;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    pointer2Apporach(arr, 5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" " ;
    }

    return 0;
}
