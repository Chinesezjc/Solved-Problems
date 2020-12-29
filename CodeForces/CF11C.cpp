//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,x,ans,cl,i;
string s,c;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		cin>>x>>s;
		i=1;
		while(s.length()<x)
		{
			c=s.substr(i,s.length()-i);
			if(s[i-1]=='2')
			{
				s+=c;
			}
			if(s[i-1]=='3')
			{
				s+=c+c;
			}
			++i;
		}
		ans=s.length();
		while(i<=x)
		{
			cl=ans-i+1000000007;
			cl%=1000000007;
			if(s[i-1]=='2')
			{
				ans+=cl;
			}
			if(s[i-1]=='3')
			{
				ans+=cl<<1;
			}
			ans%=1000000007;
			++i;
		}
		cout<<ans<<endl;
	}
	return 0;
}

