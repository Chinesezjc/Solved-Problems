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
int n,m,k,a[801],ans[2][801];
struct l{
	int a,b,v;
	bool operator > (const l &A)const
	{
		return v>A.v;
	}
}tmp,tmp2;
priority_queue <l,vector<l>,greater<l> > q;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>ans[1][i];
	}
	sort(ans[1]+1,ans[1]+1+m);
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[j];
		}
		sort(a+1,a+1+m);
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=k;++j)
		{
			tmp.a=j;
			tmp.b=j;
			tmp.v=a[j]+ans[!(i&1)][j];
			q.push(tmp);
		}
		for(int j=1;j<=k;++j)
		{
			tmp=q.top();
			q.pop();
			ans[i&1][j]=tmp.v;
			if(tmp.a==tmp.b)
			{
				tmp2.a=tmp.a;
				tmp2.b=tmp.b+1;
				tmp2.v=a[tmp2.a]+ans[!(i&1)][tmp2.b];
				q.push(tmp2);
				tmp2.a=tmp.a+1;
				tmp2.b=tmp.b;
				tmp2.v=a[tmp2.a]+ans[!(i&1)][tmp2.b];
				q.push(tmp2);
			}
			if(tmp.a<tmp.b)
			{
				tmp2.a=tmp.a;
				tmp2.b=tmp.b+1;
				tmp2.v=a[tmp2.a]+ans[!(i&1)][tmp2.b];
				q.push(tmp2);
			}
			if(tmp.a>tmp.b)
			{
				tmp2.a=tmp.a+1;
				tmp2.b=tmp.b;
				tmp2.v=a[tmp2.a]+ans[!(i&1)][tmp2.b];
				q.push(tmp2);
			}
		}
	}
	for(int i=1;i<=k;++i)
	{
		cout<<ans[n&1][i]<<' ';
	}
	return 0;
}

