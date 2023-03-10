#include <iostream>
#include <cstring>

using namespace std;

void mostFrequentCharacter(char* str, char& res, int& freq) 
{
    char *p = new char;
    int  num = 0;

    cout << *str << endl;
    p = str;
    cout << *p << endl;

    while (*p != '\0')
    {
        cout << "Success" << endl;
        cout << *p << " " << *str << endl;
        *p = tolower(*p);
        p++;
    }

    p = str;
    cout << *p << endl;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            num++;
        }
        else
        {
            str = p;
            while (*str != '\0')
            {
                if (*p == *str)
                {
                    num++;
                    *str = ' ';
                }
                str++;
            }
        }
        cout << num << endl;
        if (num > freq)
        {
            freq = res;
            res = *p;
        }
        num = 0;
        p++;
    }
}

int main()
{
    int n;
    cin >> n;
    char* str = new char[n+1];
    for(int i = 0; i < n; i++) cin >> str[i];
    str[n] = 0;
    char res = 0;
    int freq = 0;
    cout << str[0] << endl;
    mostFrequentCharacter(str, res, freq);
    cout << res << ' ' << freq;
    delete[] str;
    
    return 0;
}