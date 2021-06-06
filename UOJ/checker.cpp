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
int tot;
signed main()
{
    ios::sync_with_stdio(false);
a:
    cout << "#" << ++tot << ":";
    system("mkdataC.exe > data.in");
    int t = clock();
    int back = system("UOJ388.exe < data.in > data.out");
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
    system("UOJ388_5.exe < data.in > data.ans");
    // if (!system("fc data.out data.ans"))
    if (system("check.exe"))
    {
        goto a;
    }
    cout << "Wrong Answer!" << endl;
    return 0;
}