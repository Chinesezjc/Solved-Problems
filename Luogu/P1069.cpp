//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m1,m2,s[30001],m[15001],p[15001],ans=INF,now,cnt;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m1>>m2;
	for(int i=2;i<=m1;++i)
	{
		if(m1%i==0)
		{
			++cnt;
			p[cnt]=i;
			while(m1%i==0)
			{
				++m[cnt];
				m1/=i;
			}
		}
	}
	for(int i=1;i<=cnt;++i)
	{
		m[i]*=m2;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		now=0;
		for(int j=1;j<=cnt;++j)
		{
			if(s[i]%p[j]==0)
			{
				int l=0;
				while(s[i]%p[j]==0)
				{
					++l;
					s[i]/=p[j];
				}
				now=max(now,m[j]/l+(m[j]%l>0));
			}
			else
			{
				now=INF;
				break;
			}
		}
		ans=min(now,ans);
	}
	cout<<(ans==INF?-1:ans);
	return 0;
}

