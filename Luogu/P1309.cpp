//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,r,q,ac,bc;
struct PLAYER{
	int v,f,l;
}p[200001],a[100001],b[100001];
bool cmp(const PLAYER &A,const PLAYER &B)
{
	return A.v==B.v?A.f<B.f:A.v>B.v;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	freopen("a.in","r",stdin);
	cin>>n>>r>>q;
	m=n<<1;
	for(int i=1;i<=m;++i)
	{
		cin>>p[i].v;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>p[i].l;
		p[i].f=i;
	}
	sort(p+1,p+1+m,cmp);
	while(r>0)
	{
		--r;
		for(int i=1;i<=n;++i)
		{
			if(p[(i<<1)-1].l>p[i<<1].l)
			{
				++p[(i<<1)-1].v;
				a[i]=p[(i<<1)-1];
				b[i]=p[i<<1];
			}
			else
			{
				++p[i<<1].v;
				a[i]=p[i<<1];
				b[i]=p[(i<<1)-1];
			}
		}
		ac=bc=1;
		while(ac<=n&&bc<=n)
		{
			while(cmp(a[ac],b[bc])&&ac<=n)
			{
				p[ac+bc-1]=a[ac];
				++ac;
			}
			while(cmp(b[bc],a[ac])&&bc<=n)
			{
				p[ac+bc-1]=b[bc];
				++bc;
			}
		}
		while(ac<=n)
		{
			p[ac+bc-1]=a[ac];
			++ac;
		}
		while(bc<=n)
		{
			p[ac+bc-1]=b[bc];
			++bc;
		}
	}
	cout<<p[q].f;
	return 0;
}

