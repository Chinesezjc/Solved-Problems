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
    system("mkdata.exe > data.in");
    system("std.exe < data.in > data.ans");
    cout << "Running..." << endl;
    int t = clock();
    int back = system("CF1396D < data.in > data.out");
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
    system("check.exe");
    ifstream in("data.log");
    in >> ans;
    if (ans == "OK")
    {
        cout << "OK" << endl;
        goto a;
    }
    cout << "Wrong Answer!" << endl;
    return 0;
}