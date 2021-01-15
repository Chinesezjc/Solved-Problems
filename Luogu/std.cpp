#include <bits/stdc++.h>
using namespace std;
queue<int> f;
int n, k, q, a[100001], b[1001];
int main()
{
	scanf("%d%d", &n, &k);
	memset(a, -1, sizeof(a));
	f.push(n);
	a[n] = 0;
	while (!f.empty())
	{
		q = f.front();
		f.pop();
		if (q == k)
			break;
		b[0] = q - 1;
		b[1] = q + 1;
		b[2] = q * 2;
		for (int i = 0; i < 3; i++)
			if (b[i] >= 0 && b[i] < 100001 && a[b[i]] == -1)
			{
				f.push(b[i]);
				a[b[i]] = a[q] + 1;
			}
	}
	printf("%d", a[k]);
	return 0;
}
