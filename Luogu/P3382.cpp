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
int n;
double l, r, a[13];
double f(double x)
{
	double res = 0;
	for (int i = n; i--;)
		res = res * x + a[i];
	return res;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> n >> l >> r;
	++n;
	for (int i = n; i--;)
		std::cin >> a[i];
	while (r - l > eps)
	{
		double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
		if (f(mid1) < f(mid2))
			l = mid1;
		else
			r = mid2;
	}
	std::cout << std::fixed << std::setprecision(20) << l << std::endl;
	return 0;
}