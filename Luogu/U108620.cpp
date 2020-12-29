//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int x[20001],y[20001],cnta,cntb,cntc,cntd,cntnow,minx[10001],miny[10001],n,m,X,Y,dp[10001],ans;
struct Line{
	int x,y;
	bool operator < (const Line &TMP)const
	{
		return x==TMP.x?y<TMP.y:x<TMP.x;
	}
}a[10001],b[10001],c[10001],d[10001],now[10001];
signed main()
{
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=-n;i<=n;++i)
	{
		cin>>x[i+n];
	}
	for(int i=-n;i<=n;++i)
	{
		cin>>y[i+n];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>X>>Y;
		if(X>0&&Y>0)
		{
			++cnta;
			a[cnta].x=X;
			a[cnta].y=Y;
		}
		if(X<0&&Y>0)
		{
			++cntb;
			b[cntb].x=X;
			b[cntb].y=Y;
		}
		if(X<0&&Y<0)
		{
			++cntc;
			c[cntc].x=X;
			c[cntc].y=Y;
		}
		if(X>0&&Y<0)
		{
			++cntd;
			d[cntd].x=X;
			d[cntd].y=Y;
		}
	}
	sort(a+1,a+1+cnta);
	cntnow=0;
	++cntnow;
	now[cntnow].x=a[1].x;
	now[cntnow].y=a[1].y;
	for(int i=2;i<=cnta;++i)
	{
		if(a[i].y<=a[i-1].y||a[i].x==a[i-1].x)
		{
			continue;
		}
		++cntnow;
		now[cntnow].x=a[i].x;
		now[cntnow].y=a[i].y;
	}
	fill(minx+1,minx+1+cntnow,INF);
	for(int j=1;j<now[1].x;++j)
	{
		minx[1]=min(minx[1],x[j+n]);;
	}
	for(int i=2;i<=cntnow;++i)
	{
		for(int j=now[i-1].x+1;j<=now[i].x;++j)
		{
			minx[i]=min(minx[i],x[j+n]);
		}
	}
	fill(miny+1,miny+1+cntnow,INF);
	for(int i=1;i<cntnow;++i)
	{
		for(int j=now[i].y+1;j<=now[i+1].y;++j)
		{
			miny[i]=min(miny[i],y[j+n]);
		}
	}
	for(int j=now[cntnow].y+1;j<=n;++j)
	{
		miny[cntnow]=min(miny[cntnow],y[j+n]);
	}
	fill(dp+1,dp+1+cntnow,INF);
	for(int i=1;i<=cntnow;++i)
	{
		for(int j=0;j<i;++j)
		{
			dp[i]=min(dp[i],dp[j]+minx[j+1]*miny[i]);
		}
	}
	if(cnta>0)
	{
		ans+=dp[cntnow];
	}
//	cout<<dp[cntnow]<<endl;
	for(int i=-n;i<0;++i)
	{
		swap(x[i+n],x[-i+n]);
	}
	for(int i=1;i<=cntb;++i)
	{
		b[i].x=-b[i].x;
	}
	sort(b+1,b+1+cntb);
	cntnow=0;
	++cntnow;
	now[cntnow].x=b[1].x;
	now[cntnow].y=b[1].y;
	for(int i=2;i<=cntb;++i)
	{
		if(b[i].y<=b[i-1].y||b[i].x==b[i-1].x)
		{
			continue;
		}
		++cntnow;
		now[cntnow].x=b[i].x;
		now[cntnow].y=b[i].y;
	}
	fill(minx+1,minx+1+cntnow,INF);
	for(int j=1;j<now[1].x;++j)
	{
		minx[1]=min(minx[1],x[j+n]);;
	}
	for(int i=2;i<=cntnow;++i)
	{
		for(int j=now[i-1].x+1;j<=now[i].x;++j)
		{
			minx[i]=min(minx[i],x[j+n]);
		}
	}
	fill(miny+1,miny+1+cntnow,INF);
	for(int i=1;i<cntnow;++i)
	{
		for(int j=now[i].y+1;j<=now[i+1].y;++j)
		{
			miny[i]=min(miny[i],y[j+n]);
		}
	}
	for(int j=now[cntnow].y+1;j<=n;++j)
	{
		miny[cntnow]=min(miny[cntnow],y[j+n]);
	}
	fill(dp+1,dp+1+cntnow,INF);
	for(int i=1;i<=cntnow;++i)
	{
		for(int j=0;j<i;++j)
		{
			dp[i]=min(dp[i],dp[j]+minx[j+1]*miny[i]);
		}
	}
	if(cntb>0)
	{
		ans+=dp[cntnow];
	}
//	cout<<dp[cntnow]<<endl;
	for(int i=-n;i<0;++i)
	{
		swap(y[i+n],y[-i+n]);
	}
	for(int i=1;i<=cntd;++i)
	{
		c[i].x=-c[i].x;
		c[i].y=-c[i].y;
	}
	sort(c+1,c+1+cntc);
	cntnow=0;
	++cntnow;
	now[cntnow].x=c[1].x;
	now[cntnow].y=c[1].y;
	for(int i=2;i<=cntc;++i)
	{
		if(c[i].y<=c[i-1].y||c[i].x==c[i-1].x)
		{
			continue;
		}
		++cntnow;
		now[cntnow].x=c[i].x;
		now[cntnow].y=c[i].y;
	}
	fill(minx+1,minx+1+cntnow,INF);
	for(int j=1;j<now[1].x;++j)
	{
		minx[1]=min(minx[1],x[j+n]);;
	}
	for(int i=2;i<=cntnow;++i)
	{
		for(int j=now[i-1].x+1;j<=now[i].x;++j)
		{
			minx[i]=min(minx[i],x[j+n]);
		}
	}
	fill(miny+1,miny+1+cntnow,INF);
	for(int i=1;i<cntnow;++i)
	{
		for(int j=now[i].y+1;j<=now[i+1].y;++j)
		{
			miny[i]=min(miny[i],y[j+n]);
		}
	}
	for(int j=now[cntnow].y+1;j<=n;++j)
	{
		miny[cntnow]=min(miny[cntnow],y[j+n]);
	}
	fill(dp+1,dp+1+cntnow,INF);
	for(int i=1;i<=cntnow;++i)
	{
		for(int j=0;j<i;++j)
		{
			dp[i]=min(dp[i],dp[j]+minx[j+1]*miny[i]);
		}
	}
	if(cntc>0)
	{
		ans+=dp[cntnow];
	}
//	cout<<dp[cntnow]<<endl;
	for(int i=-n;i<0;++i)
	{
		swap(x[i+n],x[-i+n]);
	}
	for(int i=1;i<=cntd;++i)
	{
		d[i].y=-d[i].y;
	}
	sort(d+1,d+1+cntd);
	cntnow=0;
	++cntnow;
	now[cntnow].x=d[1].x;
	now[cntnow].y=d[1].y;
	for(int i=2;i<=cntd;++i)
	{
		if(d[i].y<=d[i-1].y||d[i].x==d[i-1].x)
		{
			continue;
		}
		++cntnow;
		now[cntnow].x=d[i].x;
		now[cntnow].y=d[i].y;
	}
	fill(minx+1,minx+1+cntnow,INF);
	for(int j=1;j<now[1].x;++j)
	{
		minx[1]=min(minx[1],x[j+n]);;
	}
	for(int i=2;i<=cntnow;++i)
	{
		for(int j=now[i-1].x+1;j<=now[i].x;++j)
		{
			minx[i]=min(minx[i],x[j+n]);
		}
	}
	fill(miny+1,miny+1+cntnow,INF);
	for(int i=1;i<cntnow;++i)
	{
		for(int j=now[i].y+1;j<=now[i+1].y;++j)
		{
			miny[i]=min(miny[i],y[j+n]);
		}
	}
	for(int j=now[cntnow].y+1;j<=n;++j)
	{
		miny[cntnow]=min(miny[cntnow],y[j+n]);
	}
	fill(dp+1,dp+1+cntnow,INF);
	for(int i=1;i<=cntnow;++i)
	{
		for(int j=0;j<i;++j)
		{
			dp[i]=min(dp[i],dp[j]+minx[j+1]*miny[i]);
		}
	}
	if(cntd>0)
	{
		ans+=dp[cntnow];
	}
//	cout<<dp[cntnow]<<endl;
	cout<<ans<<endl;
	return 0;
}

