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
a:
    system("mkdata.exe > fib.in");
    system("boom.exe");
    cout << "Running..." << endl;
    int t = clock();
    int back = system("fib.exe");
    if (back != 0)
    {
        cout << "Runtime Error!" << endl;
        return 0;
    }
    cout << "use time:" << clock() - t << "ms" << endl;
    if (clock() - t > 5000)
    {
        cout << "Time Limit Exceeded!" << endl;
        return 0;
    }
    if (!system("fc fib.out fib.ans"))
    {
        goto a;
    }
    cout << "Wrong Answer!" << endl;
    return 0;
}