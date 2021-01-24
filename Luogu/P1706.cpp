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
std::vector<short> a;
size_t n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    a.resize(n);
    for (size_t i = 0; i != n; ++i)
        a[i] = i + 1;
    do
    {
        for (std::vector<short>::iterator i = a.begin(); i != a.end(); ++i)
            std::cout << std::setw(5) << *i;
        std::cout << std::endl;
    } while (std::next_permutation(a.begin(), a.end()));
    return 0;
}