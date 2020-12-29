//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
string ans,s[25];
int m,cnt[25],len[25],nxt;
bool check(int L,int R)
{
	int l=cnt[L],r=cnt[R];
	while(l<len[L]&&r<len[R])
	{
		if(s[L][l]<s[R][r])
		{
			return false;
		}
		if(s[L][l]>s[R][r])
		{
			return true;
		}
		++l;
		++r;
	}
	if(l<len[L])
	{
		return false;
	}
	if(r<len[R])
	{
		return true;
	}
	return false;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>s[++m])
	{
		len[m]=s[m].length();
	}
	--m;
	s[0].push_back(127);
	do
	{
		nxt=0;
		for(int i=1;i<=m;++i)
		{
			if(cnt[i]<len[i]&&check(nxt,i))
			{
				nxt=i;
			}
		}
		if(nxt==0)
		{
			break;
		}
		else
		{
			cout<<s[nxt][cnt[nxt]];
			++cnt[nxt];
		}
	}
	while(true);
	return 0;
}

