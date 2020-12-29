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
}A,B,C;

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

Matrix fast_power(Matrix a,int n)
{
	Matrix tmp=eye(a.m);
	while(n>0)
	{
		if(n&1)
		{
			tmp=tmp*a;
		}
		n>>=1;
		a=a*a;
	}
	return tmp;
}
int fastread(string s,int mod)
{
	int tmp=0,len=s.length();
	for(int i=0;i<len;++i)
	{
		tmp=(tmp<<3)+(tmp<<1)+s[i]-'0';
		tmp%=mod;
	}
	tmp+=mod;
	return tmp;
}
string s1,s2;
int n,m,a,b,c,d;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s1>>s2>>a>>b>>c>>d;
	if(a==1)
	{
		n=fastread(s1,1000000007);
	}
	else
	{
		n=fastread(s1,1000000006);
	}
	if(c==1)
	{
		m=fastread(s2,1000000007);
	}
	else
	{
		m=fastread(s2,1000000006);
	}
	A.n=2;
	A.m=2;
	A.num[1][1]=a;
	A.num[1][2]=0;
	A.num[2][1]=b;
	A.num[2][2]=1;
	A=fast_power(A,m-1);
	B.n=2;
	B.m=2;
	B.num[1][1]=c;
	B.num[1][2]=0;
	B.num[2][1]=d;
	B.num[2][2]=1;
	C=A*B;
	C=fast_power(C,n-1);
	C=C*A;
	A.n=1;
	A.m=2;
	A.num[1][1]=1;
	A.num[1][2]=1;
	B=A*C;
	cout<<B.num[1][1];
	return 0;
}

