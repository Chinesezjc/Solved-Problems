//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
struct EDGE{
	int n,t;
}e[400];
struct POINT{
	int x,y,e;
	bool operator < (const POINT &tmp)const
	{
		return e>tmp.e;
	}
}p[50];
int head[50],n,can[50],cnt,m,k,ans,c[50][50];
void add(int f,int t)
{
	++cnt;
	e[cnt].t=t;
	e[cnt].n=head[f];
	head[f]=cnt;
}
int w(int tmp)
{
	return tmp*tmp;
}
int C(int i,int j)
{
	if(j==0||i==j)
	{
		return c[i][j]=1;
	}
	if(c[i][j])
	{
		return c[i][j];
	}
	else
	{
		return c[i][j]=(C(i-1,j-1)+C(i-1,j))%9901;
	}
}
void dfs(int i,int now)
{
	if(now==k)
	{
		++ans;
		if(ans==9901)
		{
			ans=0;
		}
//		cout<<"Oh,that's good!";
		return;
	}
	int tmp=0;
	for(int j=i;j<=m;++j)
	{
		if(!can[j])
		{
			++tmp;
		}
	}
	if(tmp+now<k)
	{
		return;
	}
	if(p[i].e==0)
	{
		ans=(ans+C(tmp,k-now))%9901;
		return;
	}
	if(!can[i])
	{
		for(int j=head[i];j;j=e[j].n)
		{
			if(!can[e[j].t])
			{
				can[e[j].t]=i;
			}
		}
//		cout<<i<<'{';
		dfs(i+1,now+1);
//		cout<<'}';
		for(int j=head[i];j;j=e[j].n)
		{
			if(can[e[j].t]==i)
			{
				can[e[j].t]=0;
			}
		}
	}
	dfs(i+1,now);
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			if(w(p[i].x-p[j].x)+w(p[i].y-p[j].y)==5)
			{
				++p[i].e;
			}
		}
	}
	sort(p+1,p+1+m);
//	for(int i=1;i<=m;++i)
//	{
//		cout<<p[i].e<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=m;++i)
	{
		for(int j=i+1;j<=m;++j)
		{
			if(w(p[i].x-p[j].x)+w(p[i].y-p[j].y)==5)
			{
				add(i,j);
//				cout<<i<<' '<<j<<endl;
			}
		}
	}
	dfs(1,0);
	cout<<ans%9901;
	return 0;
}

