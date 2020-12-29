//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int ans[256],n;
string l[3501];
string a[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
string b[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string c[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string d[4 ]={"","M","MM","MMM"};
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int A=0;A*1000<=n;++A)
	{
		for(int B=0;B<10;++B)
		{
			for(int C=0;C<10;++C)
			{
				for(int D=0;D<10;++D)
				{
					int now=A*1000+B*100+C*10+D;
					if(now==0)
					{
						continue;
					}
					if(now>n)
					{
						break;
					}
					l[now]=d[A]+c[B]+b[C]+a[D];
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		int len=l[i].length();
		for(int j=0;j<len;++j)
		{
			++ans[l[i][j]];
		}
	}
	if(ans['I'])
	{
		cout<<'I'<<' '<<ans['I']<<endl;
	}
	if(ans['V'])
	{
		cout<<'V'<<' '<<ans['V']<<endl;
	}
	if(ans['X'])
	{
		cout<<'X'<<' '<<ans['X']<<endl;
	}
	if(ans['L'])
	{
		cout<<'L'<<' '<<ans['L']<<endl;
	}
	if(ans['C'])
	{
		cout<<'C'<<' '<<ans['C']<<endl;
	}
	if(ans['D'])
	{
		cout<<'D'<<' '<<ans['D']<<endl;
	}
	if(ans['M'])
	{
		cout<<'M'<<' '<<ans['M']<<endl;
	}
	return 0;
}

