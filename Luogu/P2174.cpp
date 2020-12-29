//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 317847191
using namespace std;
const int q71=1387153,q113=1020576,q173=785883,q229=1248575;
int n,m,tmp,b,s,sum=1,x,y,a[1000001],cnt,s71=q71,s113=q113,s173=q173,s229=q229,ans71,ans113,ans173,ans229,_71,_113,_173,_229;
struct NUM{
	int v,t;
}num[1000001];
char c;
inline int power(int A,int B,int C)
{
	int TMP=1;
	while(B)
	{
		if(B&1)
		{
			TMP=(TMP*A)%C;
		}
		B>>=1;
		A=(A*A)%C;
	}
	return TMP;
}
inline void exgcd(int X,int Y)
{
	if(Y==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(Y,X%Y);
	int TMP=x;
	x=y;
	y=TMP-X/Y*y;
}
inline void d(int now)
{
	int l=s,r=b,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(num[mid].v<now)
		{
			l=mid+1;
			continue;
		}
		if(num[mid].v>now)
		{
			r=mid-1;
			continue;
		}
		if(num[mid].v==now)
		{
			--num[mid].t;
			return;
		}
	}
	--num[l].t;
}
inline void write(int now)
{
	if(now==0)
	{
		putchar('0');
	}
	char s[100];
	int len=0;
	while(now)
	{
		s[len++]=now%10+'0';
		now/=10;
	}
	while(len)
	{
		putchar(s[--len]);
	}
	putchar('\n');
}
inline void read(int &now)
{
	now=0;
	char cc=getchar();
	while('0'>cc||'9'<cc)
	{
		cc=getchar();
	}
	while('0'<=cc&&cc<='9')
	{
		now=(now<<3)+(now<<1)+(cc^'0');
		cc=getchar();
	}
}
inline void rd(char &now)
{
	now=getchar();
	while('A'>now||now>'Z')
	{
		now=getchar();
	}
}
signed main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		tmp=a[i];
		while(tmp%71==0)
		{
			++_71;
			s71=s71*71%(MOD/71);
			tmp/=71;
		}
		while(tmp%113==0)
		{
			++_113;
			s113=s113*113%(MOD/113);
			tmp/=113;
		}
		while(tmp%173==0)
		{
			++_173;
			s173=s173*173%(MOD/173);
			tmp/=173;
		}
		while(tmp%229==0)
		{
			++_229;
			s229=s229*229%(MOD/229);
			tmp/=229;
		}
		sum=(sum*tmp)%MOD;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=num[cnt].v)
		{
			num[++cnt].v=a[i];
		}
		++num[cnt].t;
	}
	s=1;
	b=cnt;
	while(m)
	{
		--m;
		rd(c);
		if(c=='D')
		{
			read(tmp);
			d(tmp);
			while(tmp%71==0)
			{
				--_71;
				s71=s71*q71%(MOD/71);
				tmp/=71;
			}
			while(tmp%113==0)
			{
				--_113;
				s113=s113*q113%(MOD/113);
				tmp/=113;
			}
			while(tmp%173==0)
			{
				--_173;
				s173=s173*q173%(MOD/173);
				tmp/=173;
			}
			while(tmp%229==0)
			{
				--_229;
				s229=s229*q229%(MOD/229);
				tmp/=229;
			}
			exgcd(tmp,MOD);
			sum=(sum*(x%MOD+MOD))%MOD;
		}
		if(c=='B')
		{
			while(!num[b].t)
			{
				--b;
			}
			write(num[b].v);
		}
		if(c=='S')
		{
			while(!num[s].t)
			{
				++s;
			}
			write(num[s].v);
		}
		if(c=='M')
		{
			while(!num[b].t)
			{
				--b;
			}
			while(!num[s].t)
			{
				++s;
			}
			write(power(num[b].v,num[s].v,MOD));
		}
		if(c=='T')
		{
			if(_71)
			{
				ans71=71*s71;
			}
			else
			{
				ans71=1;
			}
			if(_113)
			{
				ans113=113*s113;
			}
			else
			{
				ans113=1;
			}
			if(_173)
			{
				ans173=173*s173;
			}
			else
			{
				ans173=1;
			}
			if(_229)
			{
				ans229=229*s229;
			}
			else
			{
				ans229=1;
			}
			write(sum*ans71%MOD*ans113%MOD*ans173%MOD*ans229%MOD);
		}
	}
	return 0;
}

