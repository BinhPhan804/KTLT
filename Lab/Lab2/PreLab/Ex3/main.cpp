#include <iostream>

using namespace std;

void printPattern(int n)
{
	cout << n << " ";
    if (n <= 0) return;
    printPattern(n - 5);
    cout << n << " ";
}

int main()
{
    printPattern(16);

    return 0;
}