//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
#define left true
#define right false
using namespace std;
string s;
int a,b,t,len;
bool to[30];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a>>b;
	s.assign(a+b,' ');
	for(int i=a-1;i>=0;--i)
	{
		cin>>s[i];
		to[i]=right;
	}
	for(int i=a;i<a+b;++i)
	{
		cin>>s[i];
		to[i]=left;
	}
	cin>>t;
	while(t)
	{
		--t;
		for(int i=1;i<s.length();++i)
		{
			if(to[i-1]==right&&to[i]==left)
			{
				swap(to[i-1],to[i]);
				swap(s[i-1],s[i]);
				++i;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}

