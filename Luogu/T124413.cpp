//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int l,r,sumf,ans=INF,deq[5000001],dl,dr,n,m,s[5000001],f[5000001];
void read(int &x)
{
	char c=getchar();
	x=0;
	while('0'>c||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		read(f[i]);
		read(s[i]);
	}
	l=1;
	r=1;
	dl=1;
	dr=1;
	deq[dr]=1;
	sumf=f[1];
	while(sumf<m)
	{
		++r;
		sumf+=f[r];
		while(dl<=dr&&s[deq[dr]]<=s[r])
		{
			--dr;
		}
		deq[++dr]=r;
	}
    ans=min(ans,s[deq[dl]]);
	while(r<n)
	{
		++r;
		sumf+=f[r];
		while(dl<=dr&&s[deq[dr]]<=s[r])
		{
			--dr;
		}
		deq[++dr]=r;
		while(sumf-f[l]>=m)
		{
			sumf-=f[l];
			++l;
		}
		while(deq[dl]<l)
		{
			++dl;
		}
        ans=min(ans,s[deq[dl]]);
	}
	cout<<ans<<endl;
	return 0;
}
