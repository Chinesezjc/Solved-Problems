//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string x;
int y,n,m,l;
stack<int> a;
stack<char> b;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>x;
	l=x.length();
	for(int i=0;i<l;++i)
	{
		if('0'<=x[i]&&x[i]<='9')
		{
			y=(y<<3)+(y<<1)+x[i]-'0';
		}
		else
		{
			a.push(y);
			if(x[i]=='+')
			{
				while(!b.empty()&&b.top()=='*')
				{
					n=a.top();
					a.pop();
					m=a.top();
					a.pop();
					a.push(n*m%10000);
					b.pop();
				}
			}
			b.push(x[i]);
			y=0;
		}
	}
	a.push(y);
	while(!b.empty()&&b.top()=='*')
	{
		n=a.top();
		a.pop();
		m=a.top();
		a.pop();
		a.push((n*m)%10000);
		b.pop();
	}
	while(!b.empty())
	{
		n=a.top();
		a.pop();
		m=a.top();
		a.pop();
		a.push((n+m)%10000);
		b.pop();
	}
	cout<<a.top()%10000;
	return 0;
}

