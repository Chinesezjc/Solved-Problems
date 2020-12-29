//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s;
int ans,now,n,p[1000003];
signed main()
{
	cin>>s;
	n=s.length();
	for(int i=0;i<n>>1;++i)
	{
		swap(s[i],s[n-i-1]);
	}
	s=' '+s;
	for(int i=1;i<=n;++i)
	{
		p[i]=s[i]-'0';
	}
	for(int i=1;i<=n+1;++i)
	{
		if(p[i]==10)
		{
			p[i]=0;
			++p[i+1];
		}
		if(p[i]>=6||(p[i]==5&&p[i+1]>=5))
		{
			ans+=10-p[i];
			++p[i+1];
			continue;
		}
		if(p[i]<=5)
		{
			ans+=p[i];
		}
	}
	cout<<ans;
	return 0;
}

