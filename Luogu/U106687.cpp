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
int n,x[201],y[201],cnt;
double tmp;
map <double,bool> ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
		for(int j=1;j<i;++j)
		{
			if(x[i]-x[j]==0)
			{
				tmp=INF;
			}
			else
			{
				tmp=(y[i]-y[j])*1.0/(x[i]-x[j]);
			}
			if(ans[tmp])
			{
				continue;
			}
			else
			{
				ans[tmp]=true;
				++cnt;
			}
		}
	}
	cout<<cnt;
	return 0;
}

