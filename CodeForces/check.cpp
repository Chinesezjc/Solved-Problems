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
ifstream out("data.out"), ans("data.ans");
ofstream lg("data.log");
string a, b;
signed main()
{
    ios::sync_with_stdio(false);
    while (ans >> b)
    {
        if (!(out >> a) || a != b)
        {
            lg << a << ' ' << b << endl
               << "Wrong Answer!" << endl;
            return 0;
        }
    }
    lg << "OK" << endl;
    return 0;
}