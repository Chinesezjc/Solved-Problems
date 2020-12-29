//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include"E:\模板\数据结构\高精度.h"
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
bool flag;
int len;
HAA n;
string get(HAA now)
{
	if(now.n==1&&now.num[0]==0)
	{
		return "";
	}
	return get(now/27)+(char)(now%27-1+'a');
}
string a,ans1,ans2;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>a;
	n.read(a);
	cout<<2<<endl;
	for(int i=1;!flag;++i)
	{
		flag=true;
		ans1=get(n-n+i);
		ans2=get(n+i);
		int len=ans1.length();
		for(int i=0;i<len;++i)
		{
			if('a'>ans1[i]||'z'<ans1[i])
			{
				flag=false;
			}
		}
		len=ans2.length();
		for(int i=0;i<len;++i)
		{
			if('a'>ans2[i]||'z'<ans2[i])
			{
				flag=false;
			}
		}
		if(flag)
		{
			cout<<ans1<<endl<<ans2<<endl;
		}
	}
	return 0;
}

