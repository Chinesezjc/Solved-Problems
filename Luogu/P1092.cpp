//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a[3];
int n,ans[27],nextn[27],cnt;
bool used[27];
void dfs(int x)
{
	if(ans[a[0][n]]!=-1&&ans[a[1][n]]!=-1&&ans[a[0][n]]+ans[a[1][n]]>=n)
	{
		return;
	}
	if(ans[a[0][1]]!=-1&&ans[a[1][1]]!=-1&&ans[a[2][1]]!=-1&&(ans[a[0][1]]+ans[a[1][1]])%n!=ans[a[2][1]])
	{
		return;
	}
	for(int i=2;i<=n;++i)
	{
		if(ans[a[0][i]]!=-1&&ans[a[1][i]]!=-1&&ans[a[2][i]]!=-1&&!((ans[a[0][i]]+ans[a[1][i]])%n==ans[a[2][i]]||(ans[a[0][i]]+ans[a[1][i]]+1)%n==ans[a[2][i]]))
		{
			return;
		}
	}
	if(x-1==n)
	{
		int u=0;
		for(int i=1;i<=n;++i)
		{
			u/=n;
			u+=ans[a[0][i]]+ans[a[1][i]];
			if(u%n!=ans[a[2][i]])
			{
				return;
			}
		}
		for(int i=n-1;i>=0;--i)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
		exit(0);
	}
	for(int i=n-1;i>=0;--i)
	{
		if(!used[i])
		{
			ans[nextn[x]]=i;
			used[i]=true;
			dfs(x+1);
			used[i]=false;
			ans[nextn[x]]=-1;
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	fill(ans+1,ans+1+n,-1);
	for(int i=0;i<3;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;++i)
	{
		a[i]=' '+a[i];
		for(int j=1;j<=n>>1;++j)
		{
			swap(a[i][j],a[i][n-j+1]);
		}
		for(int j=1;j<=n;++j)
		{
			a[i][j]-='A'-1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(!used[a[j][i]])
			{
				used[a[j][i]]=true;
				nextn[++cnt]=a[j][i];
			}
		}
	}
	fill(used+1,used+1+n,false);
	dfs(1);
	return 0;
}

