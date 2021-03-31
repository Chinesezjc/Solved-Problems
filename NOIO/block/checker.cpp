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
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
string ans;
signed main()
{
    ios::sync_with_stdio(false);
    int t, back;
a:
    system("mkdata.exe > block.in");
    t = clock();
    back = system("block.exe");
    if (back)
    {
        cout << "Runtime Error!" << endl;
        return 0;
    }
    cout << "use time:" << clock() - t << "ms" << endl;
    if (clock() - t > 1000)
    {
        cout << "Time Limit Exceeded!" << endl;
        return 0;
    }
    t = clock();
    system("boom.exe");
    cout << "use time:" << clock() - t << "ms" << endl;
    if (!system("fc block.out block.ans"))
    // if (system("check.exe"))
    {
        goto a;
    }
    cout << "Wrong Answer!" << endl;
    return 0;
}