//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,sum[1000001],p[1000001],cnt,l,r;
bool s[1000001];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	s[1]=true;
	for(int i=1;i<=m;++i)
	{
		if(!s[i])
		{
			p[++cnt]=i;
		}
		for(int j=1;j<=cnt;++j)
		{
			if(p[j]*i>m)
			{
				break;
			}
			s[p[j]*i]=true;
			if(i%p[j]==0)
			{
				break;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		sum[i]=sum[i-1]+(!s[i]);
	}
	while(n>0)
	{
		--n;
		cin>>l>>r;
		if(l<1||r>m)
		{
			cout<<"Crossing the line\n";
			continue;
		}
		cout<<sum[r]-sum[l-1]<<endl;
	}
	return 0;
}

