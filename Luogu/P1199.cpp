//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[501][501],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		sort(a[i]+1,a[i]+1+n);
		ans=max(a[i][n-1],ans);
	}
	cout<<1<<endl<<ans;
	return 0;
}

