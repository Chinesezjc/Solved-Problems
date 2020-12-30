#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define R register int
#define UP(U) U + turn *sum
#define RI(U) U + ((turn + 1) & 3) * sum
#define DO(U) U + ((turn + 2) & 3) * sum
#define LE(U) U + ((turn + 3) & 3) * sum
#define MD(U) U + (sum << 2) //上面几个用来计算对应点的数组下标，上下左右中。。。
const int INF = 2147483647, N = 20009, M = 200009;
int sum, P = 1, S = 0, T;			 //sum方格总数，P建图循环变量，S、T为源汇点
int he[N], ne[M], to[M], f[M], c[M]; //f流量，c费用
int q[N], d[N], pre[N];				 //q队列，d距离，pre记录最短路
bool inq[N];						 //标记是否在队列中
inline void in(R &z)				 //快读
{
	register char c = getchar();
	while (c < '-')
		c = getchar();
	z = c & 15;
	c = getchar();
	while (c > '-')
		z *= 10, z += c & 15, c = getchar();
}
inline void add(R u, R v, R flow, R cost, R tp) //建边，tp表示染色属性
{
	if (tp)
	{
		tp = u;
		u = v;
		v = tp;
	} //如果是奇数点，所有的边都要反向，要流出去
	to[++P] = v;
	ne[P] = he[u];
	he[u] = P;
	c[P] = cost;
	f[P] = flow;
	to[++P] = u;
	ne[P] = he[v];
	he[v] = P;
	c[P] = -cost;
}
#define PB(X)     \
	q[t] = X;     \
	if (++t == N) \
	t = 0
#define PF(X)      \
	if (--h < 0)   \
		h = N - 1; \
	q[h] = v
inline bool spfa() //模板，加了两种优化
{
	R h = 0, t = 1, i, u, v, dn, cnt = 1, sum = 0;
	for (i = S + 1; i <= T; ++i)
		d[i] = INF;
	q[0] = S;
	inq[0] = 1;
	while (h != t)
	{
		u = q[h];
		if (++h == N)
			h = 0;
		if (d[u] * cnt > sum)
		{
			PB(u);
			continue;
		} //LLL优化
		--cnt;
		sum -= d[u];
		for (i = he[u]; i; i = ne[i])
			if (f[i] && d[v = to[i]] > (dn = d[u] + c[i]))
			{
				if (inq[v])
					sum -= d[v];
				else
				{
					inq[v] = 1;
					++cnt;
					if (d[v] < d[q[h]])
					{
						PB(v);
					}
					else
					{
						PF(v);
					} //SLF优化
				}
				pre[v] = i;
				sum += (d[v] = dn);
			}
		inq[u] = 0;
	}
	return d[T] != INF;
}
int main()
{
	R n, m, i, j, k = 1, t, shape, turn, totf = 0, mf = 0, mc = 0; //totf总流量，mf最大可行流，mc最小总费用
	in(n);
	in(m);
	sum = n * m;
	T = sum * 5 + 1;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j, ++k)
		{
			turn = 0;		 //turn下面会用来翻转，将同类型的水管归类到一起
			t = (i + j) & 1; //t是染色属性，只要判断奇偶
			if (t)
				add(S, MD(k), INF, 0, 0);
			else
				add(MD(k), T, INF, 0, 0);
			if (i)
				add(DO(k - m), UP(k), 1, 0, t);
			if (j)
				add(RI(k - 1), LE(k), 1, 0, t);
			in(shape);
			if (shape & 1)
				add(UP(k), MD(k), 1, 0, t), ++totf; //统计总流量
			if (shape & 2)
				add(RI(k), MD(k), 1, 0, t), ++totf; //因为每个流拆成了两段
			if (shape & 4)
				add(DO(k), MD(k), 1, 0, t), ++totf; //所以最终结果会是实际的两倍
			if (shape & 8)
				add(LE(k), MD(k), 1, 0, t), ++totf; //中点与四周点连边
			switch (shape)
			{
			case 8:
				++turn; //1000 ←
			case 4:
				++turn; //0100 ↓
			case 2:
				++turn; //0010 →
			case 1:		//0001 ↑
				add(RI(k), UP(k), 1, 1, t);
				add(DO(k), UP(k), 1, 2, t);
				add(LE(k), UP(k), 1, 1, t);
				break; //这四种形状内部连边情况是一样的，转一下统一处理就方便些了，下面同理
			case 9:
				++turn; //1001 ┘
			case 12:
				++turn; //1100 ┐
			case 6:
				++turn; //0110 ┌
			case 3:		//0011 └
				add(DO(k), UP(k), 1, 1, t);
				add(LE(k), RI(k), 1, 1, t);
				break;
			case 13:
				++turn; //1101 ┤
			case 14:
				++turn; //1110 ┬
			case 7:
				++turn; //0111 ├
			case 11:	//1011 ┴
				add(DO(k), LE(k), 1, 1, t);
				add(DO(k), UP(k), 1, 2, t);
				add(DO(k), RI(k), 1, 1, t);
				break;
			}
		}
	while (spfa())
	{
		m = INF; //这里m记下流量
		for (i = T; i != S; i = to[k ^ 1])
		{
			k = pre[i];
			if (m > f[k])
				m = f[k];
		}
		mf += m;
		for (i = T; i != S; i = to[k ^ 1])
		{
			k = pre[i];
			f[k] -= m;
			f[k ^ 1] += m;
			mc += m * c[k];
		}
	}
	printf("%d", totf == mf << 1 ? mc : -1); //注意如果没能流满就输-1
	return 0;
}