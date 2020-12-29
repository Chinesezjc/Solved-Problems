//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,a[1001],ans,p[1000001],s[1000001],cnt,tmp,sum;
int gcd(int A,int B)
{
	return A%B?gcd(B,A%B):B;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ans=1;
		for(int i=1;i<=n;++i)
		{
			ans*=a[i]/gcd(ans,a[i]);
		}
		tmp=ans;
		cnt=0;
		for(int i=2;i*i<=tmp;++i)
		{
			if(tmp%i==0)
			{
				p[++cnt]=i;
				s[cnt]=0;
				while(tmp%i==0)
				{
					++s[cnt];
					tmp/=i;
				}
			}
		}
		if(tmp>1)
		{
			p[++cnt]=tmp;
			s[cnt]=1;
		}
		if(cnt==1)
		{
			cout<<ans*p[1]<<endl;
		}
		else
		{
			sum=1;
			for(int i=1;i<=cnt;++i)
			{
				sum*=s[i]+1;
			}
			if(sum-n==2&&ans>a[n])
			{
				cout<<ans<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}

