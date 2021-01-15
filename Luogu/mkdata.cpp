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
#include <random>
#include <chrono>
#include <windows.h>
using namespace std;
#define int long long
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n, m;
signed main()
{
    ios::sync_with_stdio(false);
    n = Rand() % 100001;
    m = Rand() % 100001;
    cout << n << ' ' << m << endl;
    return 0;
}