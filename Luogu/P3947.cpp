//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,t,dp[1<<22],from[1<<22],used[1<<22],cost[23],leave[23],s;
string name[23];
void output(int now)
{
	if(now==0)
	{
		return;
	}
	output(now^(1<<from[now]));
	cout<<name[from[now]+1]<<endl;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>t;
	for(int i=1;i<=n;++i)
	{
		cin>>name[i]>>cost[i]>>leave[i];
	}
	s=1<<n;
	for(int i=0;i<s;++i)
	{
		dp[i]=-1;
		for(int j=0;j<n;++j)
		{
			if(i&(1<<j))
			{
				used[i]+=cost[j+1];
			}
		}
	}
	dp[0]=0;
	if(used[s-1]>t)
	{
		cout<<"No Answer"<<endl;
		return 0;
	}
	for(int now=0;now<s;++now)
	{
		for(int i=n-1;i>=0;--i)
		{
			if(now&(1<<i))
			{
				int tmp=dp[now^(1<<i)]+max(0ll,leave[i+1]-used[now^(1<<i)]-cost[i+1]);
				if(dp[now]<tmp)
				{
					dp[now]=tmp;
					from[now]=i;
				}
			}
		}
	}
	if(dp[s-1]<m)
	{
		cout<<"No Answer"<<endl;
		return 0;
	}
	cout<<dp[s-1]<<endl;
	output(s-1);
	return 0;
}

