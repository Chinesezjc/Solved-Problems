//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans,n,x,times;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x;
		if(x!=ans)
		{
			if(times==0)
			{
				ans=x;
			}
			else
			{
				--times;
			}
		}
		else
		{
			++times;
		}
	}
	cout<<ans;
	return 0;
}

