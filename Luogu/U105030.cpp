//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s,t;
int a,b,c;
string l(char x,char y)
{
	string ans="";
	if(x<y&&(('0'<=x&&y<='9')||('a'<=x&&y<='z')))
	{
		if(x+1==y)
		{
			return ans;
		}
		for(char i=x+1;i<y;++i)
		{
			for(int j=1;j<=b;++j)
			{
				ans+=i;
			}
		}
	}
	else
	{
		ans+='-';
		return ans;
	}
	if(a==2&&'a'<=x&&y<='z')
	{
		for(string::iterator p=ans.begin();p!=ans.end();++p)
		{
			*p=*p-'a'+'A';
		}
	}
	if(a==3)
	{
		for(string::iterator p=ans.begin();p!=ans.end();++p)
		{
			*p='*';
		}
	}
	if(c==2)
	{
		int len=ans.length();
		for(int i=0;i<len>>1;++i)
		{
			swap(ans[i],ans[len-1-i]);
		}
	}
	return ans;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b>>c>>s;
	s=" "+s+"     ";
	for(string::iterator p=s.begin()+1;p+1!=s.end();++p)
	{
		if(*p=='-')
		{
			t+=l(*(p-1),*(p+1));
		}
		else
		{
			t+=*p;
		}
	}
	cout<<t;
	return 0;
}

