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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::string s;
std::string concat(std::string A, std::string B) { return A + B; }
std::string reverse(std::string x)
{
    std::reverse(x.begin(), x.end());
    return x;
}
std::string substr(std::string x, int l, int r, int m = 1)
{
    x = x.substr(l, r - l);
    std::string res;
    for (int i = 0; i != (int)x.size(); ++i)
        if (i % m == 0)
            res += x[i];
    return res;
}
std::string getname(int pos)
{
    std::string res;
    while (pos != (int)s.size() && isalpha(s[pos]))
        res += tolower(s[pos++]);
    return res;
}
std::pair<std::string, int> work(int l)
{
    if (s[l] == '\"')
    {
        int pos = s.find('\"', l + 1) + 1;
        return std::make_pair(s.substr(l + 1, pos - l - 2), pos);
    }
    if (isdigit(s[l]))
    {
        int pos = l;
        while (pos != (int)s.size() && isdigit(s[pos]))
            ++pos;
        return std::make_pair(s.substr(l, pos - l), pos);
    }
    std::string name = getname(l);
    if (name == "concat")
    {
        std::pair<std::string, int> A = work(l + name.size() + 1),
                                    B = work(A.second + 1);
        return std::make_pair(concat(A.first, B.first), B.second + 1);
    }
    else if (name == "reverse")
    {
        std::pair<std::string, int> A = work(l + name.size() + 1);
        return std::make_pair(reverse(A.first), A.second + 1);
    }
    else if (name == "substr")
    {
        std::pair<std::string, int> A = work(l + name.size() + 1),
                                    B = work(A.second + 1),
                                    C = work(B.second + 1),
                                    D = s[C.second] == ',' ? work(C.second + 1) : std::make_pair("1", C.second);
        return std::make_pair(substr(A.first, atoi(B.first.c_str()) - 1, atoi(C.first.c_str()), atoi(D.first.c_str())),
                              D.second + 1);
    }
    std::cerr << "ERROR" << std::endl;
    exit(114514);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    std::cout << "\"" << work(0).first << "\"" << std::endl;
    return 0;
}