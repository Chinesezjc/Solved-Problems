//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int l,r,p,x[100001],cnt,ans,fa[100001],i,j;
bool s[100001];
int find(int now)
{
	return fa[now]==now?now:fa[now]=find(fa[now]);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>l>>r>>p;
	cout<<"TEST"<<endl;
	ans=r-l+1;
	s[1]=true;
	for(i=2;i<=r;++i)
	{
		if(!s[i])
		{
			x[++cnt]=i;
		}
		for(j=1;j<=cnt;++j)
		{
			if(i*x[j]>r)
			{
				break;
			}
			s[i*x[j]]=true;
			if(i%x[j]==0)
			{
				break;
			}
		}
	}
	for(i=l;i<=r;++i)
	{
		fa[i]=i;
	}
	i=1;
	while(x[i]<p)
	{
		++i;
	}
	for(;i<=cnt;++i)
	{
		for(j=(l-1)/x[i]+1;(j+1)*x[i]<=r;++j)
		{
			if(find(j*x[i])!=find((j+1)*x[i]))
			{
				fa[find(j*x[i])]=find((j+1)*x[i]);
				--ans;
			}
		}
	}
	cout<<ans;
	return 0;
}

