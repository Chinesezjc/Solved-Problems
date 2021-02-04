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
using namespace std;
string a, b;
int line;
ifstream ans("data.ans"), out("data.out");
signed main()
{
    ios::sync_with_stdio(false);
    while (ans >> a && out >> b)
    {
        ++line;
        // std::cout << a << endl
        //           << b << endl;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i])
            {
                cout << "first wrong appeared:" << line << ' ' << i + 1 << std::endl;
                return 0;
            }
    }
    return 0;
}