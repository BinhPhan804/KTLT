#include <iostream>
#include<string>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int gcdRecursion(int p, int q)
{
    if (p == 0) return q;
    if (q == 0) return p;
    return gcdRecursion(q, p % q);
}
int gcdIteration(int p, int q)
{
    int temp = 0;

    while (p != 0 && q != 0)
    {
        temp = p;
        p = q;
        q = temp % q;
    }
    if (q == 0) return p;
    else return q;
}

int main()
{
    int p,q;
    cin>>p>>q;
    cout<<gcdRecursion(p,q)<< " "<<gcdIteration(p,q);
    return 0;
}