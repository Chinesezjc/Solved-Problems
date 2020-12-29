//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a,m,ans;
map <int,bool> appeared;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>a;
		m=1;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			m*=10;
		}
		appeared.clear();
		while(!appeared[a])
		{
			appeared[a]=true;
			ans=max(a,ans);
			a*=a;
			while(a>=m)
			{
				a/=10;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

