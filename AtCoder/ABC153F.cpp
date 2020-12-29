//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,d,a,now,ans,tmp;
struct M{
	int x,h,l;
}m[200002];
bool cmp(const M &A,const M &B)
{
	return A.x<B.x;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>d>>a;
	d<<=1;
	for(int i=1;i<=n;++i)
	{
		cin>>m[i].x>>m[i].h;
	}
	sort(m+1,m+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		while(m[now].x<=m[i].x+d&&now<=n)
		{
			++now;
		}
		tmp=max((m[i].h-m[i].l*a)/a+((m[i].h-m[i].l*a)%a>0),i-i);
		ans+=tmp;
		m[now].l-=tmp;
		m[i].l+=tmp;
		m[i+1].l+=m[i].l;
	}
	cout<<ans;
	return 0;
}

