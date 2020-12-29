#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#define int long long
using namespace std;
int t, a, b, n, q, cnt, num[10001], que[10001], ans;
void dfs(int x, int sum)
{
    while (x < cnt)
    {
        ++x;
        dfs(x, que[++q] = sum * num[x] * -1);
    }
}
signed main(void)
{
    ios::sync_with_stdio(false);
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> a >> b >> n;
        cnt = 0;
        q = 0;
        ans = b - a + 1;
        for (int i = 2; i * i <= n; ++i)
        {
            if (!(n % i))
            {
                num[++cnt] = i;
                while (!(n % i))
                {
                    n /= i;
                }
            }
        }
        n > 1 ? num[++cnt] = n : false;
        dfs(0, -1);
        a -= 1;
        for (int i = 1; i <= q; ++i)
        {
            ans -= b / que[i] - a / que[i];
        }
        cout << "Case #" << T << ": " << ans << endl;
    }
    return 0;
}