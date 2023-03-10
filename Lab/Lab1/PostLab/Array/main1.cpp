#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else 
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int specialCells(int arr[][1000], int row, int col) 
{
    long int sumRow     =   0;
    long int sumCol     =   0;
    int      result     =   0;
    vector<long int> arrSumRow = {};
    vector<long int> arrSumCol = {};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sumRow += arr[i][j];
        }
        arrSumRow.emplace_back(sumRow);
        sumRow = 0;
    }
    
    // for (int i : arrSumRow)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sumCol += arr[i][j];
        }
        arrSumCol.push_back(sumCol);
        sumCol = 0;
    }

    // for (int i : arrSumCol)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (prime(arrSumCol[j]) && prime(arrSumRow[i]))
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    int arr[][1000] = {{1,87,26},{97,95,88},{57,60,46}};;
cout << specialCells(arr,3,3);
    return 0;
}