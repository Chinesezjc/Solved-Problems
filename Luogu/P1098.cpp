#include<cstdio>
#include<string>
#include<iostream>
#define int long long
using namespace std;
inline void rd(int &ddd)
{
	char tmp=getchar();
	int xxx=1;
	ddd=0;
	while(('0'>tmp||tmp>'9')&&tmp!='-')
	{
		tmp=getchar();
	}
	if(tmp=='-')
	{
		xxx=-1;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
	ddd*=xxx;
}
string a,b;
int p[4];
void add(char x,int y)
{
	while(y>0)
	{
		--y;
		b+=x;
	}
}
signed main()
{
	for(int i=1;i<=3;++i)
	{
		rd(p[i]);
	}
	cin>>a;
	for(int len=a.length(),i=0;i<len;++i)
	{
		add(a[i],1);
		if(a[i+1]=='-'&&a[i]<a[i+2]&&!((('0'<=a[i]&&a[i]<='9')||a[i]=='-')&&'a'<=a[i+2]&&a[i+2]<='z')&&!(a[i]=='-'&&'0'<=a[i+2]&&a[i+2]<='9'))
		{
			if(p[1]==1)
			{
				if(p[3]==1)
				{
					for(char j=a[i]+1;j<a[i+2];++j)
					{
						add(j,p[2]);
					}
				}
				if(p[3]==2)
				{
					for(char j=a[i+2]-1;j>a[i];--j)
					{
						add(j,p[2]);
					}
				}
			}
			if(p[1]==2)
			{
				if('0'<=a[i]&&a[i]<='9')
				{
					if(p[3]==1)
					{
						for(char j=a[i]+1;j<a[i+2];++j)
						{
							add(j,p[2]);
						}
					}
					if(p[3]==2)
					{
						for(char j=a[i+2]-1;j>a[i];--j)
						{
							add(j,p[2]);
						}
					}
				}
				if('a'<=a[i]&&a[i]<='z')
				{
					if(p[3]==1)
					{
						for(char j=a[i]+1;j<a[i+2];++j)
						{
							add(j-'a'+'A',p[2]);
						}
					}
					if(p[3]==2)
					{
						for(char j=a[i+2]-1;j>a[i];--j)
						{
							add(j-'a'+'A',p[2]);
						}
					}
				}
			}
			if(p[1]==3)
			{
				add('*',p[2]*(a[i+2]-a[i]-1));
			}
			++i;
		}
	}
	cout<<b;
	return 0;
}

