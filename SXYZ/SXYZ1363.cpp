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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
ifstream in("add.in");
ofstream out("add.out");
#define cin in
#define cout out
int n, a[200005], ans;
vector<int> tmp;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 10; i <= 10000000000; i *= 10)
    {
        tmp.clear();
        for (int j = 1; j <= n; ++j)
        {
            tmp.push_back(a[j] % i);
        }
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < (int)tmp.size(); ++j)
        {
            if (tmp[j] << 1 >= i)
            {
                ans += tmp.size() - j - 1;
                continue;
            }
            ans += tmp.end() - lower_bound(tmp.begin(), tmp.end(), i - tmp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}