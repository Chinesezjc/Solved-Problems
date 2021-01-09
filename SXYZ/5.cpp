//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define pi 3.141592653589793
using namespace std;
int power(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=c;
		}
		a*=a;
		a%=c;
		b>>=1;
	}
	return ans;
}

const int SSS=(1<<20)-1;
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int x=1463030063184/1792928999*1792928999;x;x-=1792928999)
	{
		if(x * ((x & -x) + ((x - (x & -x)) & -(x - (x & -x)))) == 1463030063184)
		{
			cout<<x<<endl;
//			return 0;
		}
//		if(!(x&SSS))cout<<x<<endl;
	}
	return 0;
}

