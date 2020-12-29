//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string a,b,c;
int len,k;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	len=b.length();
	k=a.length();
	for(int i=0;i<k;++i)
	{
		if('A'<=a[i]&&a[i]<='Z')
		{
			a[i]+='a'-'A';
		}
	}
	for(int i=0;i<len;++i)
	{
		c+=b[i]-(a[i%k]-'a');
		if(c[i]<'A'||('a'<=b[i]&&c[i]<'a'))
		{
			c[i]+=26;
		}
	}
	cout<<c;
	return 0;
}

