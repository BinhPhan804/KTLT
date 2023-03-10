#include "knight.h"

int sum(int n)
{
    int sum = 0;
    int res = 99;
    for (int i =0; i < n; i++)
    {
        sum += res;
        res -= 2;
    }
    return sum;
}

// tim so nguyen to gan nhat
bool prime(int n)
{
    if (n < 2)
        return false;
    else 
    {
        for (int i = 2; i <= n/2; i++)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

int findPrime(int n)
{
    n++;
    while (prime(n) == false)
    {
        n++;
    }
    return n;
}
//-------------------------------------------------------------------------------------------------

//tim so Fibo gan nhat
int* fibo(int n)
{
    int* arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

int findFibo(int n)
{
    int* arr = fibo(16);
    for (int i = 16; i >= 0; i--)
    {
        if (n > *(arr + i))
            return *(arr + i);
    }
    return 0;
}
//------------------------------------------------------------------------------------------------

//tim so lon nhat, so nho nhat, vi tri
int findIndexLastMax(int* arr, int size)
{
    int max     =   *arr;
    int index   =   0;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) >= max)
        {
            index = i;
            max = *(arr + i);
        }
    }
    return index;
}

int findIndexLastMin(int* arr, int size)
{
    int min     =   *arr;
    int index   =   0;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) <= min)
        {
            index = i;
            min = *(arr + i);
        }
    }
    return index;
}

int findIndexFirstMax(int* arr, int size)
{
    int max     =   *arr;
    int index   =   0;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            index = i;
            max = *(arr + i);
        }
    }
    return index;
}

int findIndexFirstMin(int* arr, int size)
{
    int min     =   *arr;
    int index   =   0;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < min)
        {
            index = i;
            min = *(arr + i);
        }
    }
    return index;
}

// kiem tra mang day nui ---------------------------------------------------------------------------
bool checkMoutain(int* arr, int size)
{
    int index = findIndexFirstMax(arr, size);
    for (int i = 0; i < index; i++)
    {
        if (*(arr + i) >= *(arr + i + 1))
            return false;
    }
    for (int i = index; i < size - 1; i++)
    {
        if (*(arr + i) <= *(arr + i + 1))
            return false;
    }
    return true;
}

int findIndexSecondMax(int *arr, int size)
{
    if (size < 2)
    {
        return -7;
    }
    else if (size == 2)
    {
        if (*arr < *(arr + 1))
        {
            return 0;
        }
        else if (*arr > *(arr + 1))
        {
            return 1;
        }
        else
        {
            return -7;
        }
    }
    else if (*arr == *(arr + 1) && *(arr + 1) == *(arr + 2))
        return -7;
    else if (*arr == *(arr + 1) || *arr == *(arr + 2) || *(arr + 1) == *(arr + 2))
    {
        return findIndexFirstMin(arr, 3);
    }
    else
    {
        return 3 - findIndexLastMax(arr, 3) - findIndexLastMin(arr, 3);
    }
}

// -------------------------------------------------------------------------------------------------

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {

    ifstream        in(file_input);
    string          mush_ghost, aclepius_pack, merlin_pack;
    string          str = {};
    stringstream    row1, row2, row3;  // du lieu hang 2 trong file input
    size_t          index, oldIndex; // vi tri ','
    int             res; // luu du lieu tu row 2
    int             maxHP, levelO, b, oldLevel;
    int             count       =   0;  // dem ti hon va ech
    int             counti      =   0; // su kien thu i
    float           baseDame[7] =   {0, 1, 1.5, 4.5, 7.5, 9.5};
    bool            aclepius    =   true;
    bool            merlin      =   true;
    bool            arthur      =   false;
    bool            lancelot    =   false;
    bool            tiny        =   false;
    bool            frog        =   false;

    // doc file -------------------------------------------------------------------------------------------------------------------
{
    // hang 1
    if (in.fail())
    {
        cout << "Fail." << endl;
        return;
    }
    getline(in, str);
    row1 << str;
    {
        row1 >> HP;
        row1 >> level;
        row1 >> remedy;
        row1 >> maidenkiss;
        row1 >> phoenixdown;
    }

    // hang 2
    getline(in, str);
    row2 << str;

    // cout << str << endl;

    // while (!row2.eof())
    // {
    //     row2 >> res;
    //     cout << res << endl;
    // }

    // hang 3 
    in >> str;
    index = str.find(',');
    mush_ghost = str.substr(0, index);
    oldIndex = index;
    index = str.find(',', index + 1);
    aclepius_pack = str.substr(oldIndex + 1, index - oldIndex - 1);
    oldIndex = index;
    index = str.find(',', index + 1);
    merlin_pack = str.substr(oldIndex + 1, index - oldIndex - 1);

    in.close();
}

    // khoi dau
    maxHP = HP;
    if (HP == 999)
    {
        arthur = true;
    }
    else if (prime(HP))
    {
        lancelot = true;
    }

    rescue = -1;
    oldLevel = level;
    
    while (!row2.eof())
    {
        row2 >> res;
        // cout << "Success " << res << endl;
        counti++;

        if (tiny == true || frog == true)
        {
            count++;
        }

        // row2 >> res;
        // ------------                  1                ----------- //////////////////////////////////////////////////    
        if (res == 0)
        {
            rescue = 1;

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue); 
            // break;
        }

        // ------------                  2                ----------- //////////////////////////////////////////////////
        else if (res >= 1 && res <= 5)
        {
            b = counti % 10;
            levelO = counti > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO || arthur == true || lancelot == true)
            {
                level++;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level < levelO)
            {
                int damage = baseDame[res] * levelO * 10;
                HP = HP - damage;
                if (HP <= 0)
                {
                    if (phoenixdown == 0)
                    {
                        rescue = 0;
                        // break;
                    }
                    else
                    {
                        phoenixdown--;
                        tiny = false;
                        frog = false;
                        count = 0;
                        HP = maxHP;
                    }
                }
            }
            // else
            // {
            //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            // }
             
        }
        
        // ------------                  3                ----------- //////////////////////////////////////////////////
        else if (res == 6 && tiny == false && frog == false)
        {
            b = counti % 10;
            levelO = counti > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO || arthur == true || lancelot == true)
            {
                level = level + 2;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level < levelO)
            {
                if (remedy == 0)
                {
                    tiny = true;
                    if (HP >= 5)
                    {
                        HP = HP / 5;
                    }
                    else
                    {
                        HP = 1;
                    }
                }
                else
                {
                    remedy--;
                }
            }
            // else
            // {
            //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            // }
        }
        
        // ------------                  4                ----------- //////////////////////////////////////////////////
        else if (res == 7 && tiny == false && frog == false)
        {
            b = counti % 10;
            levelO = counti > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO || arthur == true || lancelot == true)
            {
                level = level + 2;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level < levelO)
            {
                if (maidenkiss == 0)
                {
                    frog = true;
                    level = 1;
                }
                else
                {
                    maidenkiss--;
                }
            }
            // else
            // {
            //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            // }
        }
        
        // ------------                  5                ----------- //////////////////////////////////////////////////
        else if (res == 11)
        {
            int n1 = ((level + phoenixdown) % 5 + 1) * 3;
            int s1 = sum(n1);

            HP = HP + (s1 % 100);
            HP = findPrime(HP);
            if (HP > maxHP)
            {
                HP = maxHP;
            }

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
        
        // ------------                  6                ----------- //////////////////////////////////////////////////
        else if (res == 12)
        {
            if (HP > 1)
            {
                HP = findFibo(HP);
            }
            // else
            // {
            //     display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            // }
        }
        
        // ------------                  8                ----------- //////////////////////////////////////////////////
        else if (res >= 15 && res <= 17)
        {
            if (res == 15)
            {
                remedy++;
                if (tiny == true)
                {
                    remedy--;
                    tiny = false;
                    HP = HP * 5;
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                    count = 0;
                }
            }
            else if (res == 16)
            {
                maidenkiss++;
                if (frog == true)
                {
                    maidenkiss--;
                    frog = false;
                    level = oldLevel;
                    count = 0;
                }
            }
            else
            {
                phoenixdown++;
            }

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
        
        // ------------                  9                ----------- //////////////////////////////////////////////////
        else if (res == 19 && aclepius == true)
        {
            in.open(aclepius_pack);
            if (in.fail())
            {
                cout << "Fail." << endl;
                break;
            }
            int r1, c1;
            in >> r1;
            in >> c1;
            int arr[r1][c1] = {};
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j  < c1; j++)
                {
                    in >> arr[i][j];
                }
            }
            for (int i = 0; i < r1; i++)
            {
                int j = 0;
                int count_asclepius = 0;
                while (j < c1 && count_asclepius < 3)
                {
                    if (arr[i][j] == 16)
                    {
                        remedy++;
                        count_asclepius++;
                        if (tiny == true)
                        {
                            remedy--;
                            tiny = false;
                            HP = HP * 5;
                            if (HP > maxHP)
                            {
                                HP = maxHP;
                            }
                            count = 0;
                        }
                    }
                    else if (arr[i][j] == 17)
                    {
                        maidenkiss++;
                        count_asclepius++;
                        if (frog == true)
                        {
                            maidenkiss--;
                            frog = false;
                            level = oldLevel;
                            count = 0;
                        }
                    }
                    else if (arr[i][j] == 18)
                    {
                        phoenixdown++;
                        count_asclepius++;
                    }
                    j++;
                }
            }
            aclepius = false;

            if (remedy > 99)
            {
                remedy = 99;
            }
            if (maidenkiss > 99)
            {
                maidenkiss = 99;
            }
            if (phoenixdown > 99)
            {
                phoenixdown = 99;
            }
            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            in.close();
        }
        
        // ------------                  12               ----------- //////////////////////////////////////////////////
        else if (res == 99)
        {
            if (arthur == true || (lancelot = true && level >= 8) || level == 10)
            {
                level = 10;
            }
            else
            {
                rescue = 0;
            }

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            // break;
        }
        
        // ------------                  13               ----------- //////////////////////////////////////////////////
        else if (res == 18 && merlin == true)
        {
            in.open(merlin_pack);
            if (in.fail())
            {
                cout << "Fail." << endl;
                break;
            }
            int         n9;
            string      s;
            in >> n9;
            for (int i = 0; i < n9; i++)
            {
                in >> s;
                if (s.find("merlin") != string :: npos || s.find("Merlin") != string :: npos)
                {
                    HP = HP + 3;
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                }
                else if ((s.find("M") != string :: npos || s.find("m") != string :: npos)
                        && (s.find("E") != string :: npos || s.find("e") != string :: npos)
                        && (s.find("R") != string :: npos || s.find("r") != string :: npos)
                        && (s.find("L") != string :: npos || s.find("l") != string :: npos)
                        && (s.find("I") != string :: npos || s.find("i") != string :: npos)
                        && (s.find("N") != string :: npos || s.find("n") != string :: npos))
                {
                    HP = HP + 2;
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                }
            }
            merlin = false;

            // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            in.close();
        }
        
        // ------------                  7                ----------- //////////////////////////////////////////////////
        else if (res > 130)// res = 13.......
        {
            stringstream str_mush;
            stringstream str_mush1;
            stringstream t;
            string mush, mush1;
            int n2;

            in.open(mush_ghost);
            if (in.fail())
            {
                cout << "Fail." << endl;
            }
            
            getline(in, mush);
            str_mush << mush;
            str_mush >> n2;

            // cout << n2 - 1 << endl;
            
            int mush_arr1[n2 + 1] = {};
            int mush_arr2[n2 + 1] = {};

            getline(in, mush);
            
            for (int i = 0; i < mush.length(); i++)
            {
                if (mush[i] == ',')
                {
                    mush[i] = ' ';
                }
            }
            
            // cout << mush << endl;

            t << mush;
            
            for (int i = 0; i < n2; i++)
            {
                t >> mush_arr1[i];
                
                // cout << mush_arr1[i] << " ";

                if (mush_arr1[i] < 0)
                {
                    mush_arr2[i] = mush_arr1[i] * (-1);
                    mush_arr2[i] = (mush_arr2[i] * 17 + 9) % 257; 
                }
                else
                {
                    mush_arr2[i] = (mush_arr1[i] * 17 + 9) % 257; 
                }
                // cout << mush_arr2[i] << " ";
            }

            // cout << endl;
            
            str_mush1 << res;
            str_mush1 >> mush1;
            
            for (int i = 2; i < mush1.length(); i++)
            {
                if (mush1[i] == '1')
                {
                    int maxi = findIndexLastMax(mush_arr1, n2);
                    int mini = findIndexLastMin(mush_arr1, n2);
                    HP = HP - (maxi + mini);
                }
                else if (mush1[i] == '2')
                {
                    int mtx, mti;
                    if (checkMoutain(mush_arr1, n2))
                    {
                        mti = findIndexFirstMax(mush_arr1, n2);
                        mtx = mush_arr1[mti];
                    }
                    else
                    {
                        mtx = -2;
                        mti = -3;
                    }
                    HP = HP - (mtx + mti);
                }
                else if (mush1[i] == '3')
                {
                    int maxi2 = findIndexFirstMax(mush_arr2, n2);
                    int mini2 = findIndexFirstMin(mush_arr2, n2);
                    HP = HP - (maxi2 + mini2);
                }
                else if (mush1[i] == '4')
                {
                    int max2_3i = findIndexSecondMax(mush_arr2, n2);
                    int max2_3x;
                    if (max2_3i == -7)
                    {
                        max2_3x = -5;
                    }
                    else
                    {
                        max2_3x = mush_arr2[max2_3i];
                    }
                    // cout << max2_3i << " " << max2_3x << endl;
                    // cout << HP << endl;
                    HP = HP - (max2_3x + max2_3i);
                }
                // cout << HP << endl;
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                else if (HP < 0)
                {
                    if (phoenixdown == 0)
                    {
                        rescue = 0;
                        break;
                    }
                    else
                    {
                        phoenixdown--;
                        tiny = false;
                        frog = false;
                        count = 0;
                        HP = maxHP;
                    }
                }

                // display(HP, level, remedy, maidenkiss, phoenixdown, rescue);                
            }
            in.close();

        }

        // remedy, maidenkiss, phoenixdown <= 99
        if (maidenkiss > 99)
        {
            maidenkiss = 99;
        }
        if (remedy > 99)
        {
            remedy = 99;
        }
        if (phoenixdown > 99)
        {
            phoenixdown = 99;
        }

        // xet dieu kien ti hon va ech
        if (count == 3)
        {
            if (tiny == true)
            {
                HP = HP * 5;
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                tiny = false;
            }
            else if (frog == true)
            {
                level = oldLevel;
                frog = false;
            }
            count = 0;
        }
                
        if (rescue == 0 || rescue == 1)
        {
            break;
        }
        else
        {
            if(row2.eof())
            {
                break;
            }
            else
            {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
        }
    }
    

    if (rescue == 0 || rescue == 1)
    {
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
    else
    {
        rescue = 1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }



    row2.clear();
    in.close();
}
