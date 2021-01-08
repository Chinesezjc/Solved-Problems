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
int k, dp[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> k;
    fill(dp, dp + k, INF);
    for (int i = 9; i; --i)
    {
        que.push({dp[i % k] = i, i % k});
    }
    while (!que.empty())
    {
        if (que.top().first != dp[que.top().second])
        {
            que.pop();
            continue;
        }
        int now = que.top().second;
        que.pop();
        for (int i = 0; i < 10; ++i)
        {
            if (dp[(now * 10 + i) % k] > dp[now] + i)
            {
                que.push({dp[(now * 10 + i) % k] = dp[now] + i, (now * 10 + i) % k});
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}