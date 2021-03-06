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
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
stack<int, vector<int>> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int sq = sqrt(n);
    for (int i = 1; i <= sq; ++i)
    {
        if (n % i == 0)
        {
            cout << i << endl;
            if (i * i != n)
            {
                st.push(n / i);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}