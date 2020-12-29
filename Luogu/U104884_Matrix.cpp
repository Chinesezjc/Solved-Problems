//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 92233720368547753
using namespace std;
int n;
int slowmul(int a,int b)
{
	int tmp=0;
	while(b)
	{
		if(b&1)
		{
			tmp+=a;
			tmp%=MOD;
		}
		b>>=1;
		a<<=1;
		a%=MOD;
	}
	return tmp;
}
struct Matrix
{
	int n,m,num[3][3];
	
	Matrix()
	{
		clear();
	}
	
	void clear()
	{
		n=m=0;
		for(int i=1;i<=2;++i)
		{
			fill(num[i]+1,num[i]+1+2,0);
		}
	}
	Matrix operator*(const Matrix x)const
	{
		Matrix tmp;
		tmp.n=n;
		tmp.m=x.m;
		for(int i=1;i<=tmp.n;++i)
		{
			for(int j=1;j<=tmp.m;++j)
			{
				for(int k=1;k<=m;++k)
				{
					tmp.num[i][j]+=slowmul(num[i][k],x.num[k][j]);
					tmp.num[i][j]%=MOD;
				}
			}
		}
		return tmp;
	}
}a,b;
Matrix eye(const int x)
{
	Matrix tmp;
	tmp.n=tmp.m=x;
	for(int i=1;i<=x;++i)
	{
		tmp.num[i][i]=1;
	}
	return tmp;
}
Matrix power(Matrix A,int B)
{
	Matrix tmp=eye(2);
	while(B)
	{
		if(B&1)
		{
			tmp=tmp*A;
		}
		B>>=1;
		A=A*A;
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	a.n=2;
	a.m=2;
	a.num[1][1]=0;
	a.num[1][2]=2;
	a.num[2][1]=0;
	a.num[2][2]=0;
	b.n=2;
	b.m=2;
	b.num[1][1]=2;
	b.num[1][2]=0;
	b.num[2][1]=1;
	b.num[2][2]=1;
	a=a*power(b,n);
	cout<<a.num[1][1];
	return 0;
}

