//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
//This code was made by Chinese_zjc_.
//This header file is about Fraction.
//It used for calculating rational number precisely.

#define int long long

int gcd(int __A,int __B)
{
	return __A%__B?gcd(__B,__A%__B):__B;
}

struct Fraction
{
	int molecule,denominator;
	
	Fraction()
	{
		denominator=1;
	}
	
	void read(int a,int b)
	{
		molecule=a;
		denominator=b;
		reduction();
	}
	
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
	
	friend void reduction_of_fractions_to_a_common_denominator(Fraction &a,Fraction &b)
	{
		a.reduction();
		b.reduction();
		int GCD=gcd(a.denominator,b.denominator);
		a.molecule*=b.denominator/GCD;
		b.molecule*=a.denominator/GCD;
		a.denominator=b.denominator=a.denominator*b.denominator/GCD;
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
		return tmp;
	}
	
	Fraction operator + (const Fraction x)const
	{
		Fraction tmp,a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		tmp.molecule=a.molecule+b.molecule;
		tmp.denominator=a.denominator;
		tmp.reduction();
		return tmp;
	}
	
	Fraction operator - (const Fraction x)const
	{
		return *this+(-x);
	}
	
	Fraction operator * (const Fraction x)const
	{
		Fraction tmp;
		tmp.molecule=molecule*x.molecule;
		tmp.denominator=denominator*x.denominator;
		tmp.reduction();
		return tmp;
	}
	
	Fraction operator / (const Fraction x)const
	{
		return *this*(x.reciprocal());
	}
	
	bool operator == (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule==b.molecule)
		{
			return true;
		}
		return false;
	}
	
	bool operator < (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule<b.molecule)
		{
			return true;
		}
		return false;
	}
	
	bool operator > (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule>b.molecule)
		{
			return true;
		}
		return false;
	}
	
	bool operator != (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule!=b.molecule)
		{
			return true;
		}
		return false;
	}
	
	bool operator <= (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule<=b.molecule)
		{
			return true;
		}
		return false;
	}
	
	bool operator >= (const Fraction x)const
	{
		Fraction a=*this,b=x;
		reduction_of_fractions_to_a_common_denominator(a,b);
		if(a.molecule>=b.molecule)
		{
			return true;
		}
		return false;
	}
	
	Fraction be(const int x)
	{
		Fraction tmp;
		tmp.molecule=x;
		tmp.denominator=1;
		return tmp;
	}
	
	Fraction be(const double x,const int l)
	{
		Fraction tmp;
		tmp.denominator=1;
		for(int i=1;i<=l;++i)
		{
			tmp.denominator*=10;
		}
		tmp.molecule=x*tmp.denominator;
		return tmp;
	}
};
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s;
int a,b,c,i,lb=1,lc=0;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	while(i<s.length()&&s[i]!='.')
	{
		a=(a<<3)+(a<<1)+(s[i]^'0');
		++i;
	}
	if(i<s.length()&&s[i]=='.')
	{
		++i;
	}
	while(i<s.length()&&s[i]!='(')
	{
		b=(b<<3)+(b<<1)+(s[i]^'0');
		lb=(lb<<3)+(lb<<1);
		++i;
	}
	if(i<s.length()&&s[i]=='(')
	{
		++i;
	}
	while(i<s.length()&&s[i]!=')')
	{
		c=(c<<3)+(c<<1)+(s[i]^'0');
		lc=(lc<<3)+(lc<<1)+9;
		++i;
	}
	Fraction ans,tmpb,tmpc;
	tmpc.molecule=c;
	tmpc.denominator=lc;
	tmpc.reduction();
	tmpb.molecule=b;
	tmpb.denominator=lb;
	tmpb.reduction();
	tmpc.denominator*=lb;
	tmpc.reduction();
	ans=tmpc+tmpb;
	ans.molecule+=a*ans.denominator;
	ans.reduction();
	cout<<ans.molecule<<'/'<<ans.denominator<<endl;
	return 0;
}

