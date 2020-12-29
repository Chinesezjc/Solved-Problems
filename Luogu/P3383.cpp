#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
bool s[100000001];
int p[10000000], n, m, cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    s[1] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (!s[i])
        {
            p[++cnt] = i;
        }
        for (int j = 1; j <= cnt; ++j)
        {
            if (i * p[j] > n)
            {
                break;
            }
            s[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    while (m > 0)
    {
        --m;
        cin >> p[0];
        cout << p[p[0]] << endl;
    }
    return 0;
}