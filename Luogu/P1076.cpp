//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int MOD=20123;
int n,m,f,num[10001][101],p[101],cnt,ans;
bool c[10001][101];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>f>>num[i][j];
			c[i][j]=f==1?true:false;
		}
	}
	cin>>f;
	for(int i=1;i<n;++i)
	{
		ans=(num[i][f]+ans)%MOD;
		cnt=0;
		for(int j=f;j<m;++j)
		{
			if(c[i][j])
			{
				p[cnt]=j;
				++cnt;
			}
		}
		for(int j=0;j<f;++j)
		{
			if(c[i][j])
			{
				p[cnt]=j;
				++cnt;
			}
		}
		f=p[(num[i][f]-1)%cnt];
	}
	ans=(num[n][f]+ans)%MOD;
	cout<<ans;
	return 0;
}

