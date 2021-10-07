#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=40;
const int M=20;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void dftand(int *a,int n,int type)
{
	int lim=1LL<<n;
	for (int mid=1;mid<lim;mid*=2)
	for (int i=0;i<lim;i+=mid*2)
	for (int j=0;j<mid;j++)
	{
		int x=a[i+j],y=a[i+j+mid];
		if (type>0) a[i+j]=x+y;
			   else a[i+j]=x-y;
	}
}
void fwtand(int *a,int *b,int *c,int n)
{
	static int A[1<<M],B[1<<M],lim=1LL<<n;
	memcpy(A,a,sizeof(A));
	memcpy(B,b,sizeof(B));
	dftand(A,n,1);
	dftand(B,n,1);
	for (int i=0;i<lim;i++) c[i]=A[i]*B[i];
	dftand(c,n,-1);
}
bool e[N][N];
int popcount[1<<M],Log[1<<M],st[N],ans=0,deg[N];
int a[2][1<<M],b[2][1<<M],c[1<<M],tot[1<<M],n,m,mid;
void dfs(int l,int r,int s,int o)
{
	if (l==r)
	{
		int S=0;
		for (int i=0;i<mid;i++)
		if (popcount[(s&st[i])>>mid]) S|=1LL<<i;
		a[o][S]++;
		return;
	}
	dfs(l+1,r,s,o);
	dfs(l+1,r,s|(1LL<<l),o^deg[l]^popcount[(st[l]&s)>>mid]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	for (int i=1;i<(1<<M);i++) popcount[i]=!popcount[i&(i-1)];
	for (int i=2;i<(1<<M);i++) Log[i]=Log[i/2]+1;
	n=read(),m=read(),mid=n/2;
	for (int i=1;i<=m;i++)
	{
		int u=read()-1,v=read()-1;
		e[u][v]=e[v][u]=1;
		st[u]|=1LL<<v;
		st[v]|=1LL<<u;
		deg[u]^=1,deg[v]^=1;
	}
	dfs(mid,n,0,0);
	for (int i=1;i<(1LL<<mid);i++)
	{
		int k=Log[i&-i];
		tot[i]=tot[i&(i-1)]^deg[k]^popcount[st[k]&i];
	}
	for (int i=0;i<(1LL<<mid);i++) b[tot[i]][i]=1;
	for (int i=0;i<=1;i++)
	for (int j=0;j<=1;j++)
	{
		fwtand(a[i],b[j],c,mid);
		for (int k=0;k<(1LL<<mid);k++) ans+=((popcount[k]&1)^i^j)==0?c[k]:0;
	}
	print(ans);

	return 0;
}