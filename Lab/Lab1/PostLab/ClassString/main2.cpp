#include <iostream>
#include <string>

using namespace std;

int process(string s)
{
    size_t size = s.length();
    size_t max = 1;
    size_t res = 1;

    for (int i = 0; i < size - 1; i++)
    {
        size_t index1 = s.find(s[i], i + 1);
        // cout << index1 << endl;
        if (index1 == string::npos)
        {
            res++;
        }
        else
        {
            for (int j = i + 1; j < index1; j++)
            {
                size_t index2 = s.find(s[j], j + 1);
                // cout << index2 << endl;
                if (index2 == string::npos)
                {
                    res++;
                }
                else
                {
                    if (index2 < index1)
                    {
                        res++;
                        break;
                    }
                    else
                    {
                        res++;
                    }
                }
            }

            if (res > max)
            {
                max = res;
            }

            res = 1;
        }
        
    if (res > max)
    {
        max = res;
    }
    }
    return max;
}

int main()
{
    string s;
    
    getline(cin, s);
    // cout << process(s);
    cout << sizeof(s) << endl;
    return 0;
}