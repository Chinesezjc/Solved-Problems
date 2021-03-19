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
#include <fstream>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
int ans, out, ansflow, outflow;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::ifstream fin("data.in");
    std::ifstream fout("data.out");
    std::ifstream fans("data.ans");
    fout >> out;
    fans >> ans;
    return ans > 5 || out == ans;
}