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
int n,a,b;
int slowmul(int A,int B)
{
	int tmp=0;
	while(B)
	{
		if(B&1)
		{
			tmp+=A;
			tmp%=MOD;
		}
		B>>=1;
		A<<=1;
		A%=MOD;
	}
	return tmp;
}
int power(int A,int B)
{
	int ans=1;
	while(B)
	{
		if(B&1)
		{
			ans=slowmul(A,ans);
		}
		A=slowmul(A,A);
		B>>=1;
	}
	return ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	a=(MOD+2-power(power(2,n-1),MOD-2))%MOD;
	b=(MOD-power(power(2,n),MOD-2))%MOD;
	cout<<MOD-slowmul(a,power(b,MOD-2));
	return 0;
}

