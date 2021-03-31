//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
#include <windows.h>
#include <random>
#include <chrono>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = Rand() % 5 + 1, m = Rand() % 5 + 1, k = Rand() % 10 + 1;
std::vector<int> A, B;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << m << ' ' << k << std::endl;
    for (int i = 1; i <= n; ++i)
        A.push_back(i);
    for (int i = 1; i <= m; ++i)
        B.push_back(i);
    std::random_shuffle(A.begin(), A.end());
    std::random_shuffle(B.begin(), B.end());
    ++B.back();
    for (auto i : A)
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : B)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}