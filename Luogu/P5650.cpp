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
int ans=-INF,n,now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;++i)
	{
		if(s[i]=='0')
		{
			++now;
			ans=max(now,ans);
		}
		else
		{
			--now;
			ans=max(now,ans);
			if(now<0)
			{
				now=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

