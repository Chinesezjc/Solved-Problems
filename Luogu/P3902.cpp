#include<cstdio>
#define mid (l+r+1)/2
using namespace std;
int num[100001],n,ans,anss[100001];
inline void rd(int &ddd)
{
	char tmp=getchar();
	ddd=0;
	while('0'>tmp&&tmp<'9')
	{
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		ddd=(ddd<<3)+(ddd<<1)+(tmp^48);
		tmp=getchar();
	}
}
inline void Find(int x)
{
    int l=0,r=ans;
    while(l+1<r)
    {
        if(anss[mid]<x)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    anss[l+1]=x;
}
int main()
{
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(num[i]);
	}
    ans=0;
    anss[0]=0;
    for(int i=1;i<=n;++i)
    {
        if(anss[ans]<num[i])
        {
            anss[++ans]=num[i];
        }
        else
        {
            Find(num[i]);
        }
    }
    printf("%d\n",n-ans);
    return 0;
}
