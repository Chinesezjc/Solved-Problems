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
int n;
double C[3000005], ans;
void work(int A, int B)
{
    C[A] = C[B] = (C[A] + C[B]) / 2;
}
void up(int A)
{
    ans += (100 - C[A]);
    C[A] = 100;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    ans = C[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        C[i] = C[i - 1] / (i * 2 - 2) * (i * 2 - 3);
        ans += C[i];
    }
    cout << fixed << setprecision(2) << ans * 420000 / n << endl;
    return 0;
}