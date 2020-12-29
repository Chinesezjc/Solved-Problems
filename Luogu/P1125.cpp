//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int has[26],maxn,minn=INF,ans;
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0,len=s.length();i<len;++i)
	{
		++has[s[i]-'a'];
	}
	for(int i=0;i<26;++i)
	{
		minn=min(minn,has[i]==0?INF:has[i]);
		maxn=max(maxn,has[i]);
	}
	ans=maxn-minn;
	if(ans<2)
	{
		cout<<"No Answer\n0";
		return 0;
	}
	for(int i=2;i<=sqrt(ans);++i)
	{
		if(!(ans%i))
		{
			cout<<"No Answer\n0";
			return 0;
		}
	}
	cout<<"Lucky Word\n"<<ans;
	return 0;
}

