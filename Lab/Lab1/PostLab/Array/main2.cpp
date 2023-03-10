#include <iostream>
#include <vector>
#include <string>

using namespace std;

int subMatrix(int arr[][1000], int row, int col) 
{
    int result = 0;
    int sum = 0;
    vector<long int> arrSum = {};

    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            arrSum.emplace_back(sum);
        }
    }

    for (int i : arrSum)
    {
        if (i % 2 != 0)
        {
            result++;
        }
    }
    return result;
}

int main()
{
    int arr[][1000] ={{44,45,89},{82,91,34},{83,87,33},{65,51,66}};
    cout << subMatrix(arr,4, 3);
}