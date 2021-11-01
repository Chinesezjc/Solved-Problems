// This Code was made by Chinese_zjc_.
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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = 20000, m = 22;
int T = 1;
std::set<int> a;
signed main()
{
    ios::sync_with_stdio(false);
    std::cout << T << std::endl;
    std::cout << n << ' ' << m << std::endl;
    a.insert(1);
    a.insert(n);
    while (a.size() < m)
        a.insert(Rand() % n + 1);
    for (auto i : a)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}