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
int X, Y, R;
int sqr(int x)
{
	return x * x;
}
int dis2(int x, int y)
{
	return sqr(x - X) + sqr(y - Y);
}
int ans;
void read(int &x)
{
	static double tmp;
	std::cin >> tmp;
	x = tmp * 10000 + 0.5;
}
int iceil(int x)
{
	return ceil(x / 10000.0) * 10000;
}
int ifloor(int x)
{
	return floor(x / 10000.0) * 10000;
}
struct num
{
	int val;
	num(int V) : val(V) {}
	friend std::istream &operator>>(std::istream &A, num &B)
	{
		static double x;
		A >> x;
		B.val = x * 10000;
		return A;
	}
	friend num operator+(const num &A, const num &B)
	{
		return A.val + B.val;
	}
};
signed main()
{
	std::ios::sync_with_stdio(false);
	read(X);
	read(Y);
	read(R);
	for (int i = iceil(Y - R); i <= ifloor(Y + R); i += 10000)
	{
		static int l = iceil(X), r = ifloor(X);
		while (dis2(l - 10000, i) <= R * R)
		{
			l -= 10000;
		}
		while (dis2(r + 10000, i) <= R * R)
		{
			r += 10000;
		}
		while (dis2(l, i) > R * R && l <= X)
		{
			l += 10000;
		}
		while (dis2(r, i) > R * R && r >= X)
		{
			r -= 10000;
		}
		ans += (r - l + 10000) / 10000;
	}
	std::cout << ans << std::endl;
	return 0;
}