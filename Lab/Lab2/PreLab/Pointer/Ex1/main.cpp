#include <iostream>

using namespace std;

int getValueAtIndex(int *ptr, int k)
{
    return *(ptr + k);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    cout << getValueAtIndex(arr, k);

    return 0;
}