//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,len;
string a;
string _2(int x)
{
	string tmp="";
	while(x)
	{
		if(x&1)
		{
			tmp='1'+tmp;
		}
		else
		{
			tmp='0'+tmp;
		}
		x>>=1;
	}
	return tmp;
}
int _3()
{
	int tmp=0;
	for(int i=0;i<len>>1;++i)
	{
		swap(a[i],a[len-i-1]);
	}
	for(int i=0,j=1;i<len;++i,j*=3)
	{
		if(a[i]=='1')
		{
			tmp+=j;
		}
	}
	return tmp;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n;
		a=_2(n);
		len=a.length();
		cout<<_3()<<endl;
	}
	return 0;
}

