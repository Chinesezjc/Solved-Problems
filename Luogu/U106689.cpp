//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,s,t[1000001],sum[1000001],tmp,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>tmp;
		++t[tmp];
	}
	for(int i=1;i<=s;++i)
	{
		sum[i]=sum[i-1]+t[i];
	}
	for(int i=1;i<=s;++i)
	{
		ans+=t[i]*sum[s-i];
		if(i<=s-i)
		{
			ans-=t[i];
		}
	}
	cout<<(ans>>1);
	return 0;
}

