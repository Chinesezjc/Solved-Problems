//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[30],has[30],b[30][30],anss=INF,m;
string choose,ans;
bool check()
{
	for(int i=1;i<=n;++i)
	{
		if(has[i]<a[i])
		{
			return false;
		}
	}
	return true;
}
void dfs(int now,int cho)
{
	if(anss<cho)
	{
		return;
	}
	if(now>m)
	{
		if((anss>cho||choose<ans)&&check())
		{
			ans=choose;
			anss=cho;
		}
		return;
	}
	dfs(now+1,cho);
	choose[now-1]='1';
	for(int i=1;i<=n;++i)
	{
		has[i]+=b[now][i];
	}
	dfs(now+1,cho+1);
	for(int i=1;i<=n;++i)
	{
		has[i]-=b[now][i];
	}
	choose[now-1]='0';
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		choose.push_back('0');
		ans.push_back('1');
		for(int j=1;j<=n;++j)
		{
			cin>>b[i][j];
		}
	}
	dfs(1,0);
	cout<<anss;
	for(int i=1;i<=m;++i)
	{
		if(ans[i-1]=='1')
		{
			cout<<' '<<i;
		}
	}
	return 0;
}

