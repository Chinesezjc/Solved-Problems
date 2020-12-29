//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a,b,q,s[100001],sum;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		++s[a];
		sum+=a;
	}
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>a>>b;
		sum+=s[a]*(b-a);
		s[b]+=s[a];
		s[a]=0;
		cout<<sum<<endl;
	}
	return 0;
}

