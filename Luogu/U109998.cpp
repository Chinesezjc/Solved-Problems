//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int p[100001],a,n,cnt;
bool check(int now)
{
	for(int i=2;i*i<=now;++i)
	{
		if(now%i==0)
		{
			return false;
		}
	}
	return true;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		if(check(a)&&a!=1)
		{
			p[++cnt]=a;
		}
	}
	if(cnt==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sort(p+1,p+1+cnt);
	for(int i=1;i<=cnt;++i)
	{
		cout<<p[i]<<endl;
	}
	return 0;
}

