//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans,t,n;
string a;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>a;
		ans=0;
		n=a.length();
		a=' '+a;
		for(int i=1;i<=n;++i)
		{
			if(a[i]=='f')
			{
				for(int j=2;i*j*j<=n;++j)
				{
					if(a[i*j]=='a')
					{
						if(a[i*j*j]=='x')
						{
							++ans;
						}
					}
				}
			}
			if(a[i]=='x')
			{
				for(int j=2;i*j*j<=n;++j)
				{
					if(a[i*j]=='a')
					{
						if(a[i*j*j]=='f')
						{
							++ans;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

