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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
struct f
{
    int a[5][7], h[5];
    bool empty()
    {
        return !(h[0] || h[1] || h[2] || h[3] || h[4]);
    }
    void print()
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j <= h[i]; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
} a;
struct l
{
    int x, y, v;
};
vector<f> t;
vector<l> d;
bool kill(f &A)
{
    bool flag = false;
    bool will[5][7];
    memset(will, false, sizeof will);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < A.h[i]; ++j)
        {
            if (A.a[i][j] == A.a[i + 1][j] && A.a[i + 1][j] == A.a[i + 2][j])
            {
                flag = true;
                will[i][j] = will[i + 1][j] = will[i + 2][j] = true;
            }
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = A.h[i] - 3; j >= 0; --j)
        {
            if (A.a[i][j] == A.a[i][j + 1] && A.a[i][j + 1] == A.a[i][j + 2])
            {
                flag = true;
                will[i][j] = will[i][j + 1] = will[i][j + 2] = true;
            }
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < A.h[i]; ++j)
        {
            if (will[i][j])
            {
                A.a[i][j] = 0;
            }
        }
    }
    return flag;
}
void down(f &A)
{
    for (int i = 0; i < 5; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < A.h[i]; ++j)
        {
            if (A.a[i][j])
            {
                int v = A.a[i][j];
                A.a[i][j] = 0;
                A.a[i][cnt++] = v;
            }
        }
        A.h[i] = cnt;
    }
}
f work(f A, l B)
{
    if (A.a[B.x + B.v][B.y])
    {
        swap(A.a[B.x + B.v][B.y], A.a[B.x][B.y]);
        while (kill(A))
        {
            down(A);
        }
    }
    else
    {
        swap(A.a[B.x + B.v][B.y], A.a[B.x][B.y]);
        A.h[B.x + B.v] = max(B.y + 1, A.h[B.x + B.v]);
        down(A);
        // A.print();
        while (kill(A))
        {
            down(A);
        }
    }
    return A;
}
void dfs(int used_time = 0)
{
    // cout << used_time;
    // if (used_time)
    //     cout << ' ' << d.back().x << ' ' << d.back().y << ' ' << d.back().v;
    // cout << endl;
    // t.back().print();
    if (t.back().empty())
    {
        for (int i = 0; i < used_time; ++i)
        {
            cout << d[i].x << ' ' << d[i].y << ' ' << d[i].v << endl;
        }
        exit(0);
    }
    if (used_time == n)
    {
        return;
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < t.back().h[i]; ++j)
        {
            if (i < 4)
            {
                d.push_back({i, j, 1});
                t.push_back(work(t.back(), d.back()));
                dfs(used_time + 1);
                t.pop_back();
                d.pop_back();
            }
            if (i > 0)
            {
                d.push_back({i, j, -1});
                t.push_back(work(t.back(), d.back()));
                dfs(used_time + 1);
                d.pop_back();
                t.pop_back();
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 114514; ++j)
        {
            cin >> a.a[i][j];
            if (a.a[i][j] == 0)
            {
                a.h[i] = j;
                break;
            }
        }
    }
    t.push_back(a);
    dfs();
    cout << -1 << endl;
    return 0;
}