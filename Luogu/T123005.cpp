//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct S{
	int l,r;
}s[100001];
struct P{
	bool lr;
	int p;
	bool operator < (const P &tmp)
	{
		return p==tmp.p?(lr&&!tmp.lr?true:false):p<tmp.p;
	}
}p[200001];
int cnt,n,Min,BEGIN,END,t,m,now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		Min=INF;
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>s[i].l>>s[i].r;
			++cnt;
			p[cnt].lr=true;
			p[cnt].p=s[i].l;
			++cnt;
			p[cnt].lr=false;
			p[cnt].p=s[i].r;
		}
		m=n<<1;
		sort(p+1,p+1+m);
		cnt=0;
		BEGIN=0;
		for(int i=1;i<=m;++i)
		{
			if(p[i].lr)
			{
				++now;
			}
			else
			{
				--now;
			}
			if(!now)
			{
				++cnt;
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(!p[i].lr)
			{
				BEGIN=i;
				break;
			}
		}
		for(int i=m;i;--i)
		{
			if(p[i].lr)
			{
				END=i;
				break;
			}
		}
		if(cnt>1)
		{
			cout<<0<<endl;
		}
		else
		{
			for(int i=1;i<BEGIN;++i)
			{
				if(p[i].lr)
				{
					++now;
				}
				else
				{
					--now;
				}
			}
			for(int i=BEGIN;i<END;++i)
			{
				if(p[i].lr)
				{
					++now;
				}
				else
				{
					--now;
				}
				Min=min(Min,now);
			}
			cout<<(Min>=INF?-1:Min)<<endl;
			now=0;
		}
	}
	return 0;
}
