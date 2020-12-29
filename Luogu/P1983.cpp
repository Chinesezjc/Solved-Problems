//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,l[1001],s[1001][1001],c[1001],maxn;
bool in[1001][1001],flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	fill(l+1,l+1+n,1);
	for(int i=1;i<=m;++i)
	{
		cin>>c[i];
		for(int j=1;j<=c[i];++j)
		{
			cin>>s[i][j];
			in[i][s[i][j]]=true;
		}
	}
	while(true)
	{
		flag=true;
		for(int i=1;i<=m;++i)
		{
			maxn=0;
			for(int j=s[i][1];j<=s[i][c[i]];++j)
			{
				if(!in[i][j])
				{
					maxn=max(maxn,l[j]);
				}
			}
			++maxn;
			for(int j=1;j<=c[i];++j)
			{
				if(maxn>l[s[i][j]])
				{
					flag=false;
					l[s[i][j]]=maxn;
				}
			}
		}
		if(flag)
		{
			break;
		}
	}
	maxn=0;
	for(int i=1;i<=n;++i)
	{
		maxn=max(maxn,l[i]);
	}
	cout<<maxn;
	return 0;
}

