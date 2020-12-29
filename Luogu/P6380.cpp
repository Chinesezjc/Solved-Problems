//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int a,b,mod;
string s,ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>s;
	if(s[0]=='1'&&a==10)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=0;i<b;++i)
	{
		mod=((mod<<3)+(mod<<1))%a;
		if(s[i]=='0')
		{
			if(i==0)
			{
				if(a==1)
				{
					ans+='2';
				}
				else
				{
					ans+='1';
				}
				mod+=ans[i]-'0';
			}
			else
			{
				if(mod==0)
				{
					ans+='1';
					++mod;
				}
				else
				{
					ans+='0';
				}
			}
		}
		else
		{
			if(mod==0)
			{
				if(i==0)
				{
					ans+=a+'0';
				}
				else
				{
					ans+='0';
				}
			}
			else
			{
				ans+=a-mod+'0';
				mod=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

