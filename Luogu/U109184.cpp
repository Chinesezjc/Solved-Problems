//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,x,y,X,Y,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>x>>y>>a>>b)
	{
		if(a>0&&b>0)
		{
			X=min(y+1,x);
			Y=min(x+1,y);
			ans=min(a*X,x)+min(b*Y,y);
		}
		if(a==0&&b>0)
		{
			ans=min(y,b);
		}
		if(a>0&&b==0)
		{
			ans=min(x,a);
		}
		if(a==0&&b==0)
		{
			ans=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}

