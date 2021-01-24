//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,cnt[1001],to[1001][1001],m,x,sg[1001],ans;
int SG(int now)
{
	if(sg[now]+1)
	{
		return sg[now];
	}
	bool s[1001];
	fill(s,s+1001,true);
	for(int i=1;i<=cnt[now];++i)
	{
		s[SG(to[now][i])]=false;
	}
	for(int i=0;i<=1000;++i)
	{
		if(s[i])
		{
			return sg[now]=i;
		}
	}
	return sg[now]=-1;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
		{
			cin>>cnt[i];
			for(int j=1;j<=cnt[i];++j)
			{
				cin>>to[i][j];
				++to[i][j];
			}
		}
		fill(sg+1,sg+1+n,-1);
		for(int i=1;i<=n;++i)
		{
			SG(i);
		}
		while(true)
		{
			cin>>m;
			if(m==0)
			{
				break;
			}
			ans=0;
			while(m)
			{
				--m;
				cin>>x;
				ans^=SG(x+1);
			}
			cout<<(ans?"WIN":"LOSE")<<endl;
		}
	}
	return 0;
}

