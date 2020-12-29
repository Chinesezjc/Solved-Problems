//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[101],ans=INF;
void dfs(int GCD1,GCD2,int day,int good)
{
	if(day>n)
	{
		ans=good;
	}
	if(__gcd(GCD,a[day])==1)
	{
		dfs(GCD*a[day],day+1,good);
	}
	for(int i=1;good+i<ans;++i)
	{
		if(__gcd(GCD1,a[day]+i)==1&&__gcd(GCD2,a[day]+i)==1)
		{
			dfs(GCD*(a[day]+i),day+1,good+i);
		}
		if(__gcd(GCD1,a[day]-i)==1&&__gcd(GCD2,a[day]-i)==1)
		{
			dfs(GCD*(a[day]-i),day+1,good+i);
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}

