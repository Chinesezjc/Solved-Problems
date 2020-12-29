//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int flag,need[7];
bool c[7],usingnamespacestd;
string s,l[7]={"<bits/stdc++.h>","<cstdio>","<iostream>","<queue>","<vector>","<stack>","<windows.h>"};
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>s)
	{
		if(s=="using")
		{
			cin>>s>>s;
			usingnamespacestd=true;
			break;
		}
		flag=false;
		for(int i=0;i<7;++i)
		{
			if(s==l[i])
			{
				c[i]=true;
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	flag=0;
//	if(!c[0])
	{
		while(cin>>s)
		{
			if(s=="scanf"||s=="printf"||s=="freopen")
			{
				if(!c[0]&&!c[1]&&!need[1])
				{
					++flag;
					need[1]=flag;
				}
			}
			if(s=="cin"||s=="cout"||s=="max"||s=="min")
			{
				if(!c[0]&&!c[2]&&!need[2])
				{
					++flag;
					need[2]=flag;
				}
			}
			if(s=="queue"||s=="priority_queue")
			{
				if(!c[0]&&!c[3]&&!need[3])
				{
					++flag;
					need[3]=flag;
				}
			}
			if(s=="vector")
			{
				if(!c[0]&&!c[4]&&!need[4])
				{
					++flag;
					need[4]=flag;
				}
			}
			if(s=="stack")
			{
				if(!c[0]&&!c[5]&&!need[5])
				{
					++flag;
					need[5]=flag;
				}
			}
			if(s=="system")
			{
				if(!c[6]&&!need[6])
				{
					++flag;
					need[6]=flag;
				}
			}
		}
	}
	if(flag==0&&usingnamespacestd)
	{
		cout<<"Yes";
	}
	else
	if(!usingnamespacestd)
	{
		cout<<"You can write using namespace std;";
	}
	else
	{
		for(int i=1;i<=flag;++i)
		{
			for(int j=1;j<=6;++j)
			{
				if(need[j]==i)
				{
					cout<<l[j]<<endl;
				}
			}
		}
	}
	return 0;
}

