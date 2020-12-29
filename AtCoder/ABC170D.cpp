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
bool can[1000005];
int n,a,has[1000005],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		++has[a];
		can[a]=(has[a]==1);
	}
	for(int i=1;i<=1000000;++i)
	{
		if(can[i])
		{
			++ans;
		}
		if(has[i])
		{
			for(int j=i<<1;j<=1000000;j+=i)
			{
				can[j]=false;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

