//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[200001],b[200001];

int gcd(int __A,int __B)
{
	return __A%__B?gcd(__B,__A%__B):__B;
}

struct Fraction
{
	int molecule,denominator;
	
	void reduction()
	{
		if(molecule==0)
		{
			denominator=1;
			return;
		}
		int GCD=gcd(molecule,denominator);
		molecule/=GCD;
		denominator/=GCD;
		if(denominator<0)
		{
			molecule=-molecule;
			denominator=-denominator;
		}
	}
	
	Fraction operator - ()const
	{
		Fraction tmp=*this;
		tmp.molecule=-tmp.molecule;
		return tmp;
	}
	
	Fraction reciprocal()const
	{
		Fraction tmp;
		tmp.molecule=denominator;
		tmp.denominator=molecule;
		tmp.reduction();
		return tmp;
	}
	
	bool operator < (const Fraction x)const
	{
		return molecule==x.molecule?denominator<x.denominator:molecule<x.molecule;
	}
}k[200002];
map <Fraction,int> l;
int cnt,s[200002],ans,t[200002],p[200002],_00,_0x,_x0;
#define MOD 1000000007
int C(int a,int b)
{
	return t[a]*p[b]%MOD*p[a-b]%MOD;
}
int power(int a,int b,int c)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=(tmp*a)%c;
		}
		b>>=1;
		a=(a*a)%c;
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	t[0]=1;
	p[0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		t[i]=t[i-1]*i%MOD;
		p[i]=power(t[i],MOD-2,MOD);
		if(a[i]==0&&b[i]==0)
		{
			++_00;
			continue;
		}
		if(a[i]==0)
		{
			++_0x;
			continue;
		}
		if(b[i]==0)
		{
			++_x0;
			continue;
		}
		k[i].molecule=a[i];
		k[i].denominator=b[i];
		k[i].reduction();
		++l[k[i]];
	}
	s[++cnt]=1;
	for(int i=1;i<=_0x;++i)
	{
		s[cnt]=(s[cnt]+C(_0x,i))%MOD;
	}
	for(int i=1;i<=_x0;++i)
	{
		s[cnt]=(s[cnt]+C(_x0,i))%MOD;
	}
	for(int i=1;i<=n;++i)
	{
		if(l[k[i]])
		{
			Fraction tmp=-k[i].reciprocal();
			s[++cnt]=1;
			int N=l[k[i]];
			for(int j=1;j<=N;++j)
			{
				s[cnt]=(s[cnt]+C(N,j))%MOD;
			}
			N=l[tmp];
			for(int j=1;j<=N;++j)
			{
				s[cnt]=(s[cnt]+C(N,j))%MOD;
			}
			l[k[i]]=l[tmp]=0;
		}
	}
	ans=1;
	for(int i=1;i<=cnt;++i)
	{
		ans=(ans*s[i])%MOD;
	}
	cout<<(ans+MOD-1+_00)%MOD<<endl;
	return 0;
}

