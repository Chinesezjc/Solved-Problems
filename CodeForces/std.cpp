#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') sum=sum*10+ch-'0',ch=getchar();
	return sum;
}
int T;
int n,k;
const int ch1=29,ch2=31;
const int mod=1e9+7;
#define ull unsigned long long
struct Pair
{
	int x;ull y;
	Pair(int x_=0,ull y_=0):x(x_),y(y_){}
	bool operator == (Pair s)const
	{
		return x==s.x&&y==s.y;
	}
	bool operator < (Pair s)const
	{
		return x==s.x?y<s.y:x<s.x;
	}
	Pair operator + (Pair s)const
	{
		return Pair((x+s.x)%mod,y+s.y);
	}
	Pair operator - (Pair s)const
	{
		return Pair((x-s.x+mod)%mod,y-s.y);
	}
	Pair operator * (Pair s)const
	{
		return Pair(1ll*x*s.x%mod,y*s.y);
	}
};
#define N 1010
struct opt
{
	Pair a,b,c;
	opt(){}
	bool operator < (opt s)const
	{
		if(a==s.a)
		{
			if(b==s.b) return c<s.c;
			else return b<s.b;
		}
		else return a<s.a;
	}
};
Pair poww[N];
void pre()
{
	Pair g=Pair(ch1,ch2);
	poww[0]=Pair(1,1);
	for(int i=1;i<=1000;i++) poww[i]=poww[i-1]*g;
}
Pair yuan(){return (poww[1]+Pair(212,23))*poww[1];}
#define fi first
#define se second
#define mp make_pair
#define pr pair<int,int>
map<opt,pr> As;
map<Pair,int> To;
pr ANS[N];int tot;
int zhan[N],oo;
struct Tu
{
	int head[N],last[N<<1],v[N<<1],p;bool vis[N];
	int A,B,Sum;
	int Size[N],mmax[N];
	Pair ff[N];
	void getsize(int a,int b,int c)
	{
		Size[a]=1;mmax[a]=0;
		for(int i=head[a];i;i=last[i])
		if(v[i]!=b&&v[i]!=c) getsize(v[i],a,c),Size[a]+=Size[v[i]],mmax[a]=max(mmax[a],Size[v[i]]);
	}
	void getrt(int a,int b,int c)
	{
		mmax[a]=max(mmax[a],Sum-Size[a]);
		if(mmax[a]<=(Sum>>1))
		{
			if(!A) A=a;
			else B=a;
		}
		for(int i=head[a];i;i=last[i])
		if(v[i]!=b&&v[i]!=c) getrt(v[i],a,c);
	}

	Pair H(int a,int b,int c)
	{
		zhan[++oo]=a;
		vis[a]=1;
		Pair uu=Pair(1,1);
		for(int i=head[a];i;i=last[i])
		if(v[i]!=b&&v[i]!=c)
		{
			Pair A=H(v[i],a,c);
			uu=uu+A;
		}
		uu=uu*poww[Size[a]];
		uu=uu+Pair(212,23);
		uu=uu*poww[1];
		return uu;
	}
	Pair gen(int a,int b,int c)
	{
		getsize(a,b,c);
		oo=0;
		return H(a,b,c);
	}
	Pair suan(int w,int s)//算一个点所在的树的hash s点不能过
	{
		A=0,B=0;
		getsize(w,s,s);Sum=Size[w];
		getrt(w,s,s);
		Pair L,R;
		if(A) L=gen(A,0,s);
		if(B) R=gen(B,0,s);
		if(L<R) swap(L,R) ;
		return L+(R*poww[1]);
	}
	void add(int a,int b)
	{
		v[++p]=b;
		last[p]=head[a];
		head[a]=p;
	}
	void reset()
	{
		memset(id,0,sizeof(id));
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		p=0;
	}
	Pair st[N];
	int num;
	void build()
	{
		for(int i=1;i<=n;i++)//枚举哪个是u
		{
			memset(vis,0,sizeof(vis));
			num=0;
			Pair ss,tt;
			for(int j=head[i];j;j=last[j])
			st[++num]=suan(v[j],i),ss=ss+st[num],Z[num]=v[j];
			for(int j=1;j<=n;j++)
			if(!vis[j]&&j!=i) tt=tt+suan(j,i);
			for(int j=0;j<=num;j++)
			{
				opt AA;
				AA.a=ss-st[j],AA.b=st[j],AA.c=tt-yuan();
				As[AA]=mp(i,Z[j]);
			}
		}
	}
	int Z[N];
	pr find(int &gf,Pair &ww)
	{
		for(int i=1;i<=n;i++)//枚举哪个是u
		{
			memset(vis,0,sizeof(vis));
			num=0;
			Pair ss,tt;
			for(int j=head[i];j;j=last[j])
			st[++num]=suan(v[j],i),ss=ss+st[num],Z[num]=v[j];
			for(int j=1;j<=n;j++)
			if(!vis[j]&&j!=i) tt=tt+suan(j,i);
			for(int j=0;j<=num;j++)
			{
				opt AA;
				AA.c=ss-st[j],AA.b=st[j],AA.a=tt-yuan();
				if(As.count(AA))//找到了
				{
					gf=As[AA].se;
					ww=AA.b;
					return AA.b==Pair(0,0)?mp(As[AA].fi,-i):mp(As[AA].fi,i);
				}
			}
		}
		return mp(-1,-1);
	}
	int id[N];
	int cnt;
	void solve(int a,int b,int c)
	{
		if(!id[a]) id[a]=++cnt;
		if(c) ANS[++tot]=mp(c,id[a]);
		vis[a]=1;
		for(int i=head[a];i;i=last[i])
		if(v[i]!=b) solve(v[i],a,id[a]);
	}
}S[2];
int lky[N],gh;
void solve()
{
	As.clear();To.clear();
	S[0].reset(),S[1].reset();
	for(int i=0;i<k;i++)
	{
		int m=read();
		for(int j=1;j<=m;j++)
		{
			int l=read(),r=read();
			S[i].add(l,r);
			S[i].add(r,l);
		}
	}
	S[0].build();
	int from;Pair to;
	pr gg=S[1].find(from,to);
	if(gg.fi==-1)
	{
		cout<<"NO\n";
		return ;
	}
	//找到了
    std::cout<<gg.fi<<" "<<gg.se<<std::endl;
	int X=gg.fi,Y=abs(gg.se);
	S[0].getsize(X,0,0);
	for(int i=S[0].head[X];i;i=S[0].last[i])
	{
		Pair AA=S[0].gen(S[0].v[i],X,X);
		To[AA]++;
	}
	memset(S[1].vis,0,sizeof(S[1].vis));
 	oo=0;Pair Ss=S[1].H(Y,0,0);
 	gh=oo,memcpy(lky,zhan,sizeof(zhan));
	tot=0;S[1].cnt=0;S[1].solve(Y,0,0);//
	int rt=++S[1].cnt;
	bool flag=0;
	for(int i=1;i<=n;i++)
	if(!S[1].vis[i])//可能搞到了删去的那个点
	{
		Pair ff=S[1].gen(i,0,0);
		if(!flag)
		{
			if(S[1].suan(i,0)==yuan())
			{
				flag=1;	for(int j=1;j<=oo;j++) S[1].vis[zhan[j]]=0;
				continue;
			}
		}
		if(To.count(ff)&&To[ff])//有 这个
		{
			S[1].solve(i,0,rt);
			To[ff]--;
		}
		else
		{
			for(int j=1;j<=oo;j++) S[1].vis[zhan[j]]=0;
		}
	}
	cout<<"YES\n";
	if(gg.se>0)
	{
		for(int i=1;i<=gh;i++)
		if(lky[i]!=Y)
		{
			Pair LL=S[1].suan(lky[i],Y);
			Pair RR=S[1].gen(lky[i],Y,Y);
			if(LL==to&&RR==S[0].gen(from,X,X))
			{
				ANS[++tot]=mp(rt,S[1].id[lky[i]]);
				break;
			}
		}
	}
	else ANS[++tot]=mp(rt,1);
//	assert(tot==n-1);
//	if(tot!=n-1)
//	{
//		cout<<"LKY";
//		exit(0);
//	}
	for(int i=1;i<n;i++) cout<<ANS[i].fi<<" "<<ANS[i].se<<'\n';
}
int main()
{
//	freopen("rnm.in","r",stdin);
//	freopen("rnm.out","w",stdout);
	pre();
	T=read();
	while(T--)
	{
		n=read(),k=read();
		solve();
	}
	return 0;
}
/*
1
5 2
3
1 2 3 4 2 3
3
5 2 2 1 1 4

*///I am a bot for remotejudge