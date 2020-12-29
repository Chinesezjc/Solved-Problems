//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
bool read(int &x)
{
	x=0;
	char c=getchar();
	while(('0'>c||'9'<c)&&c!=EOF)
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(c==EOF)
	{
		return false;
	}
	return true;
}
int a[101],cnt,ans,l,r;
char s;
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>a[++cnt]>>s);
	sort(a+1,a+1+cnt);
	l=1;
	r=cnt;
	while(l<r)
	{
		if(a[l]+a[r]<=120)
		{
			++ans;
			++l;
			--r;
		}
		else
		{
			--r;
		}
	}
	cout<<ans<<endl;
	return 0;
}

