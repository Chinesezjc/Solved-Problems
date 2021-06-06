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
bool tocan[1005], fromcan[1005];
short n, a[200005], b[200005],
    to[1005][1005], tocnt[1005], from[1005][1005], fromcnt[1005],
    toque[1005], toquel, toquer, fromque[1005], fromquel, fromquer;
int ans[200005], m;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    std::reverse(a + 1, a + 1 + m);
    std::reverse(b + 1, b + 1 + m);
    for (short i = 1; i <= n; ++i)
    {
        ++ans[0];
        memset(tocan, false, sizeof(tocan));
        memset(fromcan, false, sizeof(fromcan));
        memset(tocnt, 0, sizeof(tocnt));
        memset(fromcnt, 0, sizeof(fromcnt));
        tocan[i] = fromcan[i] = true;
        toquel = toquer = fromquel = fromquer = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[j] < i || b[j] < i)
                continue;
            if (!tocan[b[j]])
            {
                if (tocan[a[j]])
                    tocan[toque[toquer++] = b[j]] = true;
                else
                    to[a[j]][tocnt[a[j]]++] = b[j];
            }
            while (toquel != toquer)
            {
                const short &now = toque[toquel++];
                if (fromcan[now])
                    ++ans[j];
                for (short k = 0; k != tocnt[now]; ++k)
                {
                    const short &v = to[now][k];
                    if (!tocan[v])
                        tocan[toque[toquer++] = v] = true;
                }
                tocnt[now] = 0;
            }
            if (!fromcan[a[j]])
            {
                if (fromcan[b[j]])
                    fromcan[fromque[fromquer++] = a[j]] = true;
                else
                    from[b[j]][fromcnt[b[j]]++] = a[j];
            }
            while (fromquel != fromquer)
            {
                const short &now = fromque[fromquel++];
                if (tocan[now])
                    ++ans[j];
                for (short k = 0; k != fromcnt[now]; ++k)
                {
                    const short &v = from[now][k];
                    if (!fromcan[v])
                        fromcan[fromque[fromquer++] = v] = true;
                }
                fromcnt[now] = 0;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        ans[i] += ans[i - 1];
    for (int i = m; i >= 0; --i)
        std::cout << ans[i] << " \n"[i == 0];
    // std::cout << clock() << std::endl;
    return 0;
}