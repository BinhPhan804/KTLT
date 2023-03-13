#include <iostream>

using namespace std;

void insertRow(int**& matrix, int r, int c, int* rowArr, int row) 
{
    if (row > r || row < 0) return;
    matrix[r] = new int[c];
    r++;
    for (int i = r - 1; i > row; i--)
    {
        matrix[i] = matrix[i - 1];
    }
    matrix[row] = rowArr;
}

int main()
{
    int** m = new int*[2];
    m[0] = new int[2]; m[0][0] = 1; m[0][1] = 2;
    m[1] = new int[2]; m[1][0] = 1; m[1][1] = 3;
    int* row = new int[2];
    row[0] = 10;
    row[1] = 10;
    insertRow(m, 2, 2, row, 0);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    
    delete[] m;
    delete row;

    return 0;
}