//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a[100001],b[100001],n,m,ans[100001],T,C;
signed main()
{
	std::ios::sync_with_stdio(false);
//	freopen("bubble.in","r",stdin);
//	freopen("bubble.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>T>>C;
		if(T==1)
		{
			swap(a[C],a[C+1]);
		}
		if(T==2)
		{
			if(C>=n)
			{
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;++i)
			{
				b[i]=a[i];
			}
			for(int j=1;j<=C;++j)
			{
				for(int i=1;i<n;++i)
				{
					if(b[i]>b[i+1])
					{
						swap(b[i],b[i+1]);
					}
				}
			}
			bool flag=true;
			int ans=0;
			while(flag)
			{
				flag=false;
				for(int i=1;i<n;++i)
				{
					if(b[i]>b[i+1])
					{
						swap(b[i],b[i+1]);
						++ans;
						flag=true;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

