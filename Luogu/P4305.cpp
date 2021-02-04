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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, T;
struct node
{
    int v, p;
    friend bool operator==(const node &A, const node &B) { return A.v == B.v; }
};
std::vector<node> a;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        a.resize(n);
        for (int i = 0; i != n; ++i)
        {
            std::cin >> a[i].v;
            a[i].p = i;
        }
        std::sort(a.begin(), a.end(), [&](const node &A, const node &B) { return A.v == B.v ? A.p < B.p : A.v < B.v; });
        a.erase(std::unique(a.begin(), a.end()), a.end());
        std::sort(a.begin(), a.end(), [&](const node &A, const node &B) { return A.p < B.p; });
        for (int i = 0; i != a.size(); ++i)
            std::cout << a[i].v << ' ';
        std::cout << std::endl;
    }
    return 0;
}