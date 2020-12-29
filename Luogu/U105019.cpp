//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int m[14]={0,0,31,60,91,121,152,182,213,244,274,305,335,366};
bool s[367];
int now,n,ans,a,b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>a>>b;
		s[m[a]+b]=true;
	}
	for(int i=1;i<=366;++i)
	{
		if(!s[i])
		{
			++now;
			ans=max(ans,now);
		}
		else
		{
			now=0;
		}
	}
	cout<<(int)(ans*86400.0/366.0+0.5);
	return 0;
}

