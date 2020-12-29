//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,t,a,Max,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		Max=-INF;
		ans=-INF;
		cin>>n;
		while(n)
		{
			--n;
			cin>>a;
			ans=max(ans,Max-a);
			Max=max(a,Max);
		}
		cout<<ans<<endl;
	}
	return 0;
}

