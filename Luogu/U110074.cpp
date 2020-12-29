//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x[105],y[105],xx[105],yy[105],X[501],Y[501],cntx,cnty,news[501][501],l,r,ans;
bool bucket[1000005],went[505][505];
const int XX[4]={0,1,0,-1},YY[4]={1,0,-1,0};
struct QUEUE{
	int dis,x,y;
}que[250005];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;++i)
	{
		bucket[x[i]-1]=true;
		bucket[x[i]]=true;
		bucket[x[i]+1]=true;
	}
	for(int i=0;i<=1000001;++i)
	{
		if(bucket[i])
		{
			X[++cntx]=i;
			bucket[i]=false;
		}
	}
	for(int i=1;i<=n;++i)
	{
		bucket[y[i]-1]=true;
		bucket[y[i]]=true;
		bucket[y[i]+1]=true;
	}
	for(int i=0;i<=1000001;++i)
	{
		if(bucket[i])
		{
			Y[++cnty]=i;
			bucket[i]=false;
		}
	}
	for(int i=1;i<=n;++i)
	{
		xx[i]=lower_bound(X+1,X+1+cntx,x[i])-X;
		yy[i]=lower_bound(Y+1,Y+1+cnty,y[i])-Y;
		news[xx[i]][yy[i]]=i;
	}
	x[n+1]=x[1];
	y[n+1]=y[1];
	for(int i=0;i<=cntx;++i)
	{
		went[i][0]=went[i][cnty+1]=true;
	}
	for(int i=0;i<=cnty;++i)
	{
		went[0][i]=went[cntx+1][i]=true;
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=cntx;++j)
		{
			for(int k=1;k<=cnty;++k)
			{
				went[j][k]=false;
			}
		}
		l=r=0;
		++r;
		que[r].dis=0;
		que[r].x=xx[i];
		que[r].y=yy[i];
		went[que[r].x][que[r].y]=true;
		while(l<r)
		{
			++l;
			if(news[que[l].x][que[l].y]==i+1)
			{
				ans+=que[l].dis;
				break;
			}
			if(news[que[l].x][que[l].y]!=0&&news[que[l].x][que[l].y]!=i)
			{
				continue;
			}
			for(int j=0;j<4;++j)
			{
				if(que[l].x+XX[j]>=0&&que[l].y+YY[j]>=0&&que[l].x+XX[j]<=cntx&&que[l].y+YY[j]<=cnty&&!went[que[l].x+XX[j]][que[l].y+YY[j]])
				{
					++r;
					que[r].x=que[l].x+XX[j];
					que[r].y=que[l].y+YY[j];
					que[r].dis=que[l].dis+abs(X[que[l].x+XX[j]]-X[que[l].x])+abs(Y[que[l].y+YY[j]]-Y[que[l].y]);
					went[que[r].x][que[r].y]=true;
				}
			}
		}
		if(news[que[l].x][que[l].y]!=i+1)
		{
			cout<<-1;
			return 0;
		}
	}
	for(int j=1;j<=cntx;++j)
	{
		for(int k=1;k<=cnty;++k)
		{
			went[j][k]=false;
		}
	}
	l=r=0;
	++r;
	que[r].dis=0;
	que[r].x=xx[n];
	que[r].y=yy[n];
	went[que[r].x][que[r].y]=true;
	while(l<r)
	{
		++l;
		if(news[que[l].x][que[l].y]==1)
		{
			ans+=que[l].dis;
			break;
		}
		if(news[que[l].x][que[l].y]!=0&&news[que[l].x][que[l].y]!=n)
		{
			continue;
		}
		for(int j=0;j<4;++j)
		{
			if(que[l].x+XX[j]>=0&&que[l].y+YY[j]>=0&&que[l].x+XX[j]<=cntx&&que[l].y+YY[j]<=cnty&&!went[que[l].x+XX[j]][que[l].y+YY[j]])
			{
				++r;
				que[r].x=que[l].x+XX[j];
				que[r].y=que[l].y+YY[j];
				que[r].dis=que[l].dis+abs(X[que[l].x+XX[j]]-X[que[l].x])+abs(Y[que[l].y+YY[j]]-Y[que[l].y]);
				went[que[r].x][que[r].y]=true;
			}
		}
	}
	if(news[que[l].x][que[l].y]!=1)
	{
		cout<<-1;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}

