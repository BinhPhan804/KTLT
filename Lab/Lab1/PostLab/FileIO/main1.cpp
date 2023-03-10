#include <iostream>
#include <fstream>

using namespace std;

void studentGrading(string fileName)   
{
    int     n;
    float   res;
    int     arr[5] = {};
    float   GPA = 0;
    bool    check   =   true;
    
    ifstream in(fileName);
    in >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            in >> res;
            if (res < 5)
            {
                check = false;
            }
            GPA = GPA + res;
        }
        GPA = (float) GPA / 4;
        if (GPA >= 8 && check == true)
        {
            arr[0]++;
        }
        else if (GPA >= 6.5 && check == true)
        {
            arr[1]++;
        }
        else if (GPA >= 5 && check == true)
        {
            arr[2]++;
        }
        else
        {
            arr[3]++;
        }
        check = true;
        GPA = 0;
    }

    in.close();

    cout << 'A' << " " << arr[0] << endl;
    cout << 'B' << " " << arr[1] << endl;
    cout << 'C' << " " << arr[2] << endl;
    cout << 'D' << " " << arr[3];
}

int main()
{
    return 0;
}