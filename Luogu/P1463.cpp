//This code was made by Chinese_zjc_.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <iomanip>
#include <stack>
#include <bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int P[15] = {41, 37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3, 2};
int n, anss, ans;
void dfs(int t, int now, int sum)
{
    //	cout<<t<<' '<<now<<' '<<sum<<endl;
    if (t > n)
    {
        return;
    }
    if (sum > anss || (sum == anss && t < ans))
    {
        anss = sum;
        ans = t;
    }
    if (now > 12)
    {
        return;
    }
    for (int i = 0, j = 1; t <= n / j; ++i, j *= P[now])
    {
        dfs(t * j, now + 1, sum * (i + 1));
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    dfs(1, 0, 1);
    cout << ans << endl;
    return 0;
}