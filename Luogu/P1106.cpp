//This Code was made by Chinese_zjc_.
#include <iostream>
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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
void read(signed &x)
{
    x = 0;
    char c = getchar();
    while ('0' > c || c > '9')
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ '0');
        c = getchar();
    }
}
string n;
int s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    while (s--)
    {
        for (int i = 1; i < n.length(); ++i)
        {
            if (n[i - 1] > n[i])
            {
                n.erase(i - 1, 1);
                goto a;
            }
        }
        n.erase(n.length() - 1, 1);
    a:
        continue;
    }
    while (n.length() > 1 && n[0] == '0')
    {
        n.erase(0, 1);
    }
    cout << n << endl;
    return 0;
}