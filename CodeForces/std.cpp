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
const double eps = 1e-8, INF = 1e9;
using namespace std;
const int MAXN = 1000, MAXM = 10000;
double A[MAXN][MAXM];
int N, M, B, E, i, j, k, p;
double res, t, cost[MAXM], _need[MAXM];

inline void Pivot(int e, int l)
{
	cost[l] /= A[l][e], t = A[l][e], A[l][e] = 1;
	for (i = 1; i <= M; ++i)
		if (i != e)
			A[l][i] /= t;
	for (i = 1; i <= N; ++i)
		if (i != l && abs(A[i][e]) > eps)
		{
			cost[i] -= A[i][e] * cost[l];
			for (p = 1; p <= M; ++p)
				if (p != e)
					A[i][p] -= A[i][e] * A[l][p];
			A[i][e] = -A[i][e] * A[l][e];
		}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			std::cout << A[i][j] << " \n"[j == M];
	for (int i = 1; i <= M; ++i)
		std::cout << _need[i] << " \n"[i == M];
	for (int i = 1; i <= N; ++i)
		std::cout << cost[i] << " \n"[i == N];
	res += _need[e] * cost[l];
	for (i = 1; i <= M; ++i)
		if (i != e)
			_need[i] -= _need[e] * A[l][i];
	_need[e] = -_need[e] * A[l][e];
}
double simplex()
{
	while (true)
	{
		double MINX = INF;
		j = 0, k = 0;
		for (j = 1; j <= M; ++j)
			if (_need[j] > eps)
				break;
		if (j > M)
			return res;
		for (i = 1; i <= N; ++i)
			if (A[i][j] > eps && MINX > cost[i] / A[i][j])
				k = i, MINX = cost[i] / A[i][j];
		if (MINX >= INF)
			return INF;
		std::cout << j << ' ' << k << std::endl;
		Pivot(j, k);
	}
	return res;
}
int main()
{
	cin >> N >> M;
	for (i = 1; i <= N; ++i)
		scanf("%lf", &cost[i]);
	for (i = 1; i <= M; ++i)
	{
		scanf("%d%d%lf", &B, &E, &_need[i]); //约束
		for (j = B; j <= E; ++j)
			A[j][i] = 1.0;
	}
	printf("%d\n", (int)(simplex() + 0.5));
	return 0;
}