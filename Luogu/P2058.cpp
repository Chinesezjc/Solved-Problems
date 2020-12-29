//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,t[100001],k[100001],now[100001],x[300001],cnt=1,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i]>>k[i];
		k[i]+=k[i-1];
		for(int j=k[i-1]+1;j<=k[i];++j)
		{
			cin>>x[j];
			if(now[x[j]]==0)
			{
				++ans;
			}
			++now[x[j]];
		}
		while(t[cnt]<=t[i]-86400)
		{
			for(int j=k[cnt-1]+1;j<=k[cnt];++j)
			{
				if(now[x[j]]==1)
				{
					--ans;
				}
				--now[x[j]];
			}
			++cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}

