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
int n,cnt,p[20001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			++cnt;
			while(n%i==0)
			{
				n/=i;
				++p[cnt];
			}
		}
	}
	if(n>1)
	{
		++ans;
	}
	for(int i=1;i<=cnt;++i)
	{
		for(int j=1;j<=p[i];++j)
		{
			p[i]-=j;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}

