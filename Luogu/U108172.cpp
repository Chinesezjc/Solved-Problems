//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ANS=INF,TMP;
int dfs(int now,int ate,int day)
{
	if((n-ate)%now)
	{
		return -1;
	}
	if(day>1&&n%ate==0)
	{
		return day;
	}
	if(ate>n)
	{
		return -1;
	}
	int ans=INF,tmp;
	for(int i=2;i<=9;++i)
	{
		tmp=dfs(now*i,ate+now*i,day+1);
		if(tmp==-1)
		{
			continue;
		}
		ans=min(tmp,ans);
	}
	return ans==INF?-1:ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	cout<<dfs(1,1,1);
	return 0;
}

