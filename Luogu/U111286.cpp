//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int X1,X2,Y1,Y2,t,p[5134],cntp,times[5134],ans,pf[5134],cntpf;
bool isnotp[50001];
int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
void dfs(int now,int i)
{
	if(i>cntpf)
	{
		if(gcd(now,X1)==Y1&&lcm(now,X2)==Y2)
		{
			++ans;
		}
		return;
	}
	dfs(now,i+1);
	for(int j=1;j<=times[i];++j)
	{
		now*=pf[i];
		dfs(now,i+1);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=2;i<=50000;++i)
	{
		if(!isnotp[i])
		{
			p[++cntp]=i;
//			cout<<i<<endl;
			for(int j=i+i;j<=50000;j+=i)
			{
				isnotp[j]=true;
			}
		}
	}
//	cout<<cntp<<endl;
	cin>>t;
	while(t)
	{
		--t;
		cin>>X1>>Y1>>X2>>Y2;
		if(X1<Y1||X2>Y2)
		{
			cout<<0<<endl;
			continue;
		}
		int tmp=Y2;
		cntpf=0;
		for(int i=1;p[i]*p[i]<=tmp;++i)
		{
			if(tmp%p[i]==0)
			{
				pf[++cntpf]=p[i];
				times[cntpf]=0;
				while(tmp%p[i]==0)
				{
					++times[cntpf];
					tmp/=p[i];
				}
				if(X1%p[i]==0&&Y1%p[i]>0)
				{
					--cntpf;
				}
			}
		}
		if(tmp>1)
		{
			pf[++cntpf]=tmp;
			times[cntpf]=1;
		}
		ans=0;
		dfs(1,1);
		cout<<ans<<endl;
	}
	return 0;
}

