#include <iostream>

using namespace std;

int* zeros(int n) 
{
    if (n <= 0) return nullptr;
    int *arr = new int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        *(arr + i) = 0;
    }
    return arr;
}

int main()
{
    int* arr = zeros(5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}