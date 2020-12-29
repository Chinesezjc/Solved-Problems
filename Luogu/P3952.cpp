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
int T, n, g, Max;
string f;
struct L
{
    string name, from, to;
    int in;
} tmp;
stack<L> sta;
map<string, bool> used;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        while (!sta.empty())
        {
            sta.pop();
        }
        used.clear();
        cin >> n >> f;
        if (f == "O(1)")
        {
            g = 0;
        }
        else
        {
            g = atoi(f.substr(4, f.length() - 5).c_str());
        }
        Max = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> f;
            if (f == "F")
            {
                cin >> tmp.name >> tmp.from >> tmp.to;
                if (used[tmp.name])
                {
                    Max = INF;
                }
                used[tmp.name] = true;
                if (tmp.from == "n")
                {
                    if (tmp.to == "n")
                    {
                        if (sta.empty())
                        {
                            tmp.in = 0;
                        }
                        else
                        {
                            tmp.in = sta.top().in;
                        }
                        sta.push(tmp);
                    }
                    else
                    {
                        tmp.in = -INF;
                        sta.push(tmp);
                    }
                }
                else
                {
                    if (tmp.to == "n")
                    {
                        if (sta.empty())
                        {
                            tmp.in = 1;
                        }
                        else
                        {
                            tmp.in = sta.top().in + 1;
                        }
                        sta.push(tmp);
                    }
                    else
                    {
                        int v = atoi(tmp.to.c_str()) - atoi(tmp.from.c_str());
                        if (v < 0)
                        {
                            tmp.in = -INF;
                            sta.push(tmp);
                        }
                        else
                        {
                            if (sta.empty())
                            {
                                tmp.in = 0;
                            }
                            else
                            {
                                tmp.in = sta.top().in;
                            }
                            sta.push(tmp);
                        }
                    }
                }
            }
            else
            {
                if (sta.empty())
                {
                    Max = INF;
                }
                else
                {
                    Max = max(Max, sta.top().in);
                    used[sta.top().name] = false;
                    sta.pop();
                }
            }
        }
        if (Max == INF || !sta.empty())
        {
            cout << "ERR" << endl;
        }
        else
        {
            cout << (Max == g ? "Yes" : "No") << endl;
        }
    }
    return 0;
}