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
int n,m,a,ans;
bool c[500];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		c[a]=true;
	}
	for(int i=1;i<=200;++i)
	{
		if(!c[i]&&abs(m-ans)>abs(m-i))
		{
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

