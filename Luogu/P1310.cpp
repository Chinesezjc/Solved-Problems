//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
const int MOD=10007;
int len,dp[2][100001],j;
char x;
string s,r=".";
signed main()
{
//	std::ios::sync_with_stdio(false);
	cin>>len;
	while(len>0)
	{
		--len;
		cin>>x;
		while(*(s.end()-1)=='*'&&!s.empty()&&x=='+')
		{
			r+=*(s.end()-1);
			s.erase(s.end()-1);
		}
		if(x==')')
		{
			while(!s.empty()&&*(s.end()-1)!='(')
			{
				r+=*(s.end()-1);
				s.erase(s.end()-1);
			}
			s.erase(s.end()-1);
			continue;
		}
		s+=x;
		if(x!='(')
		{
			r+='.';
		}
	}
	while(!s.empty())
	{
		r+=*(s.end()-1);
		s.erase(s.end()-1);
	}
	len=r.length();
	r=' '+r;
	for(int i=1;i<=len;++i)
	{
		if(r[i]=='.')
		{
			++j;
			dp[0][j]=dp[1][j]=1;
		}
		if(r[i]=='*')
		{
			--j;
			dp[0][j]=(dp[0][j]*dp[0][j+1]+dp[1][j]*dp[0][j+1]+dp[0][j]*dp[1][j+1])%MOD;
			dp[1][j]=(dp[1][j]*dp[1][j+1])%MOD;
		}
		if(r[i]=='+')
		{
			--j;
			dp[1][j]=(dp[1][j]*dp[1][j+1]+dp[1][j]*dp[0][j+1]+dp[0][j]*dp[1][j+1])%MOD;
			dp[0][j]=(dp[0][j]*dp[0][j+1])%MOD;
		}
	}
	cout<<dp[0][1];
	return 0;
}

