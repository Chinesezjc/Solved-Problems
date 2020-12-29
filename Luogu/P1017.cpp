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
#include <ctime>
// #include<windows.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, r;
char to[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
string to_r(int now, int l)
{
    if (now == 0)
    {
        return "";
    }
    else
    {
        int tmp = now / (l * r) * (l * r);
        if (l > 0)
        {
            while (tmp > now)
            {
                tmp += l * r;
            }
        }
        else
        {
            while (tmp < now)
            {
                tmp += l * r;
            }
        }
        return to_r(tmp, l * r) + to[(now - tmp) / l];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> r;
    cout << n << '=';
    if (n == 0)
    {
        cout << 0;
    }
    else
    {
        cout << to_r(n, 1);
    }
    cout << "(base" << r << ")" << endl;
    return 0;
}