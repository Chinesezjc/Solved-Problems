//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
map <int,int> sum;
int n,a[200001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]<i)
		{
			++sum[i-a[i]];
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]<i)
		{
			--sum[i-a[i]];
		}
		ans+=sum[i+a[i]];
	}
	cout<<ans<<endl;
	return 0;
}

