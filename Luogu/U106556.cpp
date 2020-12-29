//This code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,l,s,t,flag,x[50001],y[50001],cnt,head[50001],walk;
double dis[50001][21],ans=INF;
bool went[50001];
struct EDGE{
	int n,t;
	double v;
}e[1000001];
struct vs{
	double dis;
	int p;
	bool operator < (const vs &tmp)const
	{
		return dis>tmp.dis;
	}
}tmp;
priority_queue<vs> q;
int w(int X)
{
	return X*X;
}
double D(int F,int T)
{
	return sqrt(w(x[F]-x[T])+w(y[F]-y[T]));
}
void add(int F,int T)
{
	++cnt;
	e[cnt].n=head[F];
	e[cnt].t=T;
	e[cnt].v=D(F,T);
	head[F]=cnt;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m>>l>>s>>t;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=m;++i)
	{
		int F,T;
		cin>>F>>T;
		add(F,T);
		add(T,F);
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=l;++j)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=0;i<=l;++i)
	{
		dis[s][i]=0;
	}
	tmp.p=s;
	tmp.dis=0;
	q.push(tmp);
	while(!q.empty())
	{
		int j=q.top().p;
		q.pop();
		if(went[j])
		{
			continue;
		}
		for(int k=head[j];k;k=e[k].n)
		{
			double now=dis[j][0]+e[k].v;
			if(dis[e[k].t][0]>now)
			{
				dis[e[k].t][0]=now;
				tmp.p=e[k].t;
				tmp.dis=now;
				q.push(tmp);
			}
		}
		went[j]=true;
	}
	for(int i=1;i<=l;++i)
	{
		fill(went+1,went+1+n,false);
		tmp.p=s;
		tmp.dis=0;
		q.push(tmp);
		while(!q.empty())
		{
			int j=q.top().p;
			q.pop();
			if(went[j])
			{
				continue;
			}
			went[j]=true;
			for(int k=head[j];k;k=e[k].n)
			{
				double now=min(dis[j][i]+e[k].v,dis[j][i-1]);
				if(dis[e[k].t][i]>now)
				{
					dis[e[k].t][i]=now;
					tmp.p=e[k].t;
					tmp.dis=now;
					q.push(tmp);
				}
			}
		}
	}
	cout<<fixed<<setprecision(2)<<dis[t][l];
	return 0;
}

