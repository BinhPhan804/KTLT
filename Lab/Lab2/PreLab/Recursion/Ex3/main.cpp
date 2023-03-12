#include <iostream>

using namespace std;

void printPattern(int n)
{
    if (n <= 0)
    {
        cout << n;
        return;
    }
    else cout << n << " ";
    printPattern(n - 5);
    cout << " " << n;
}

int main()
{
    printPattern(16);

    return 0;
}