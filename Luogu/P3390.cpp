//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff

using namespace std;

struct Matrix
{
	int n,m,num[101][101];
	
	Matrix()
	{
		clear();
	}
	
	void clear()
	{
		n=m=0;
		for(int i=1;i<=100;++i)
		{
			fill(num[i]+1,num[i]+1+100,0);
		}
	}
	
	Matrix operator+(const int x)const
	{
		Matrix tmp=*this;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				tmp.num[i][j]+=x;
			}
		}
		return tmp;
	}
	
	Matrix operator-(const int x)const
	{
		Matrix tmp=*this;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				tmp.num[i][j]-=x;
			}
		}
		return tmp;
	}
	
	Matrix operator*(const int x)const
	{
		Matrix tmp=*this;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				tmp.num[i][j]*=x;
			}
		}
		return tmp;
	}
	
	Matrix operator+(const Matrix x)const
	{
		if(n!=x.n||m!=x.m)
		{
			cout<<"Error:The Matrixs can not do '+'."<<endl;
			return *this;
		}
		Matrix tmp=*this;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				tmp.num[i][j]+=x.num[i][j];
			}
		}
		return tmp;
	}
	
	Matrix operator-(const Matrix x)const
	{
		if(n!=x.n||m!=x.m)
		{
			cout<<"Error:The Matrixs can not do '-'."<<endl;
			return *this;
		}
		Matrix tmp=*this;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				tmp.num[i][j]-=x.num[i][j];
			}
		}
		return tmp;
	}
	
	Matrix operator*(const Matrix x)const
	{
		if(m!=x.n)
		{
			cout<<"Error:The Matrixs can not do '*'."<<endl;
			return *this;
		}
		Matrix tmp;
		tmp.n=n;
		tmp.m=x.m;
		for(int i=1;i<=tmp.n;++i)
		{
			for(int j=1;j<=tmp.m;++j)
			{
				for(int k=1;k<=m;++k)
				{
					tmp.num[i][j]+=num[i][k]*x.num[k][j];
					tmp.num[i][j]%=1000000007;
				}
			}
		}
		return tmp;
	}
}ans,a;

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
int t;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a.n>>t;
	ans=eye(a.n);
	a.m=a.n;
	for(int i=1;i<=a.n;++i)
	{
		for(int j=1;j<=a.m;++j)
		{
			cin>>a.num[i][j];
		}
	}
	while(t>0)
	{
		if(t&1)
		{
			ans=ans*a;
		}
		t>>=1;
		a=a*a;
	}
	for(int i=1;i<=ans.n;++i)
	{
		for(int j=1;j<=ans.m;++j)
		{
			cout<<ans.num[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

