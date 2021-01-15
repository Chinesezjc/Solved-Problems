//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MAX = 20;
int s, mul, sum;
string Who = "Alice";
class Map
{
public:
    bool Alice_know_maybe[MAX][MAX], Bob_know_maybe[MAX][MAX];
    bool Alice_know_other[MAX][MAX], Bob_know_other[MAX][MAX];
    void init()
    {
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                if (i * j != mul)
                    Alice_know_maybe[i][j] = false;
                else
                    Alice_know_maybe[i][j] = true;
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                if (i + j != sum)
                    Bob_know_maybe[i][j] = false;
                else
                    Bob_know_maybe[i][j] = true;
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                if (!(s <= i && i <= j))
                {
                    Alice_know_other[i][j] = Bob_know_other[i][j] = true;
                    Alice_know_maybe[i][j] = Bob_know_maybe[i][j] = false;
                }
    }
    bool Alice_Unknow()
    {
        int cnt = 0;
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
            {
                if (Alice_know_maybe[i][j])
                    ++cnt;
                if (Alice_know_maybe[i][j] && Alice_know_other[i][j])
                    return true;
            }
        return cnt != 1;
    }
    bool Bob_Unknow()
    {
        int cnt = 0;
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
            {
                if (Bob_know_maybe[i][j])
                    ++cnt;
                if (Bob_know_maybe[i][j] && Bob_know_other[i][j])
                    return true;
            }
        return cnt != 1;
    }
    void Alice_Get_If_Bob_Unknow()
    {
        int tim[MAX + MAX];
        fill(tim, tim + MAX + MAX, 0);
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Alice_know_other[i][j] || (Alice_know_maybe[i][j] && Alice_know_other[i][j]))
                    ++tim[i + j];
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Alice_know_other[i][j] && tim[i + j] == 1)
                {
                    Alice_know_other[i][j] = true;
                    Alice_know_maybe[i][j] = false;
                }
    }
    void Bob_Get_If_Alice_Unknow()
    {
        int tim[MAX * MAX];
        fill(tim, tim + MAX * MAX, 0);
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Bob_know_other[i][j] || (Bob_know_maybe[i][j] && Bob_know_other[i][j]))
                    ++tim[i * j];
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Bob_know_other[i][j] && tim[i * j] == 1)
                {
                    Bob_know_other[i][j] = true;
                    Bob_know_maybe[i][j] = false;
                }
    }
    void Alice_Get_If_Bob_Know()
    {
        int tim[MAX + MAX];
        fill(tim, tim + MAX + MAX, 0);
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Alice_know_maybe[i][j])
                    Alice_know_other[i][j] = true;
    }
    void Bob_Get_If_Alice_Know()
    {
        int tim[MAX * MAX];
        fill(tim, tim + MAX * MAX, 0);
        for (int i = 0; i < MAX; ++i)
            for (int j = i; j < MAX; ++j)
                if (!Bob_know_maybe[i][j])
                    Bob_know_other[i][j] = true;
    }
} g;
template <class f>
void print(f d)
{
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            cout << d[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int t = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s >> mul >> sum >> Who;
    g.init();
    while (g.Alice_Unknow() && g.Bob_Unknow())
    {
        ++t;
        if (Who == "Alice")
        {
            g.Bob_Get_If_Alice_Unknow();
            Who = "Bob";
        }
        else
        {
            g.Alice_Get_If_Bob_Unknow();
            Who = "Alice";
        }
        print(g.Alice_know_other);
        print(g.Bob_know_other);
        print(g.Alice_know_maybe);
        print(g.Bob_know_maybe);
        getchar();
    }
    cout << t << endl;
    return 0;
}