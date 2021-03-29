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
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % C;
        B >>= 1;
        A = A * A % C;
    }
    return res % C;
}
int a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c;
    std::cout << a << '^' << b << " mod " << c << '=' << power(a, b, c) << std::endl;
    return 0;
}