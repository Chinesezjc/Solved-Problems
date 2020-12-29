//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string s;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>s;
	if(s[0]!='M'||s[1]!='D'||s[2]!='A')
	{
		cout<<"1 1 1 1 1"<<endl;
		return 0;
	}
	for(int i=7;i>2;--i)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			for(int j=1;j<5;++j)
			{
				if(s[i]-'0'==j||s[i]-'0'+j==10)
				{
					cout<<"1 ";
				}
				else
				{
					cout<<"0 ";
				}
			}
			if(s[i]=='5'||s[i]=='0')
			{
				cout<<"1"<<endl;
			}
			else
			{
				cout<<"0"<<endl;
			}
			return 0;
		}
	}
	return 0;
}

