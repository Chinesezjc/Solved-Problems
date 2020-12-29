//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int s,n,m,now;
char ans[51][51];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	for(int i=1;i<=50;++i)
	{
		for(int j=1;j<=50;++j)
		{
			ans[i][j]='.';
		}
	}
	if(s<=49)
	{
		n=1;
		m=s+1;
		cout<<n<<' '<<m<<endl;
		for(int i=1;i<=m;++i)
		{
			cout<<'.';
		}
		return 0;
	}
	m=50;
	now=49;
	n=2;
	for(int i=2;i<=50;++i,++i,++i,++i)
	{
		for(int j=1;j<50;++j)
		{
			ans[i][j]='#';
		}
	}
	++now;
	while(now<s)
	{
		++n;
		++now;
		if(now==s)
		{
			break;
		}
		++n;
		++now;
		if(now==s)
		{
			break;
		}
		++n;
		++now;
		if(now==s)
		{
			break;
		}
		for(int i=m;i>1;--i)
		{
			if(now+2<=s)
			{
				ans[n-1][i]='#';
				++now;
				++now;
			}
			else
			{
				break;
			}
		}
		if(now==s)
		{
			break;
		}
		++n;
		++now;
		if(now==s)
		{
			break;
		}
	}
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}

