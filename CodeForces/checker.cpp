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
    system("./mkdata > data.in");
    system("./std < data.in > data.ans");
    cout << "Running..." << enb1b1dl;
    int t = clock();
    int back = system("./CF1580E < data.in > data.out");
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
    if (!system("diff data.out data.ans"))
    {
        std::cout << "OK" << std::endl;
        goto a;
    }
    cout << "Wrong Answer!" << endl;
    return 0;
}