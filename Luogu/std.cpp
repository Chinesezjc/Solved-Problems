#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define llong long long
using namespace std;

const int P = 1e9+7;
const int N = 301;

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}
llong mulinv(llong x) {return quickpow(x,P-2);}

llong aux[N+4],aux2[N+4];
struct Polynomial
{
	vector<llong> a; int n;
	Polynomial() {}
	Polynomial(int _n) {n = _n; for(int i=0; i<=n; i++) a.push_back(0ll);}
	void clear() {n = 0; a.clear(); a.push_back(0ll);}
	void output() {printf("deg%d, ",n); for(int i=0; i<=n; i++) printf("%lld ",a[i]); puts("");}
	Polynomial operator +(Polynomial &arg) const
	{
		Polynomial ret(max(n,arg.n));
		for(int i=0; i<=min(n,arg.n); i++)
		{
			ret.a[i] = (a[i]+arg.a[i])%P;
		}
		for(int i=min(n,arg.n)+1; i<=n; i++) ret.a[i] = a[i];
		for(int i=min(n,arg.n)+1; i<=arg.n; i++) ret.a[i] = arg.a[i];
		return ret;
	}
	Polynomial operator -(Polynomial &arg) const
	{
		Polynomial ret(max(n,arg.n));
		for(int i=0; i<=min(n,arg.n); i++)
		{
			ret.a[i] = (a[i]-arg.a[i]+P)%P;
		}
		for(int i=min(n,arg.n)+1; i<=n; i++) ret.a[i] = a[i];
		for(int i=min(n,arg.n)+1; i<=arg.n; i++) ret.a[i] = P-arg.a[i];
		return ret;
	}
	Polynomial operator *(Polynomial &arg) const
	{
		Polynomial ret(n+arg.n);
		for(int i=0; i<=n; i++)
		{
			for(int j=0; j<=arg.n; j++)
			{
				ret.a[i+j] = (ret.a[i+j]+a[i]*arg.a[j])%P;
			}
		}
		return ret;
	}
	llong calc(llong x)
	{
		llong ret = 0ll;
		for(int i=n; i>=0; i--)
		{
			ret = (ret*x+a[i])%P;
		}
		return ret;
	}
	void interpoly(int _n,llong ax[],llong ay[])
	{
		n = _n; for(int i=0; i<=n; i++) a.push_back(0ll);
		for(int i=0; i<=n+1; i++) aux[i] = 0ll;
		aux[0] = 1ll;
		for(int i=0; i<=n; i++)
		{
			for(int j=i+1; j>0; j--)
			{
				aux[j] = (aux[j-1]-aux[j]*ax[i]%P+P)%P;
			}
			aux[0] = P-aux[0]*ax[i]%P;
		}
		for(int i=0; i<=n; i++)
		{
			llong tmp = 1ll;
			for(int j=0; j<=n; j++)
			{
				if(i==j) continue;
				tmp = tmp*(ax[i]-ax[j]+P)%P;
			}
			llong coe = mulinv(tmp);
			for(int j=n+1; j>=0; j--) {aux2[j] = aux[j];}
			for(int j=n; j>=0; j--)
			{
				a[j] = (a[j]+aux2[j+1]*coe%P*ay[i])%P;
				aux2[j] = (aux2[j]+ax[i]*aux2[j+1])%P;
			}
		}
	}
};
Polynomial tmp1,tmp2,tmp3;
Polynomial dp[2661][(N<<1)+3],sdp[2661][(N<<1)+3];
llong lval[2661][(N<<1)+3],rval[2661][(N<<1)+3];
int dpid[N+4][N+4];
Polynomial spw[N+4];
struct Interval
{
	llong lb,rb; //[1,2n]
} a[N+3];
vector<llong> disc;
llong spwx[N+3],spwy[N+3];
int mx[N+3][N+3];
int n,nsta;
llong ans;

int getid(llong x) {return lower_bound(disc.begin(),disc.end(),x)-disc.begin();} //no +1

Polynomial prefixsum(Polynomial poly)
{
	Polynomial ret(poly.n+1);
	for(int i=0; i<=poly.n; i++)
	{
		for(int j=0; j<=i+1; j++)
		{
			ret.a[j] = (ret.a[j]+poly.a[i]*spw[i].a[j])%P;
		}
	}
	return ret;
}

void dfs(int l,int r,int x)
{
	Polynomial tmp1,tmp2,tmp3;
	if(dpid[l][r] && dp[dpid[l][r]][x].a.size()>0) {return;}
	if(!dpid[l][r]) {nsta++; dpid[l][r] = nsta;}
	if(l==r)
	{
		if(!dpid[l][r]) {nsta++; dpid[l][r] = nsta;}
		dp[dpid[l][r]][x] = Polynomial(0); dp[dpid[l][r]][x].a[0] = (x>=a[l].lb&&x<=a[l].rb) ? 1ll : 0ll;
		sdp[dpid[l][r]][x] = prefixsum(dp[dpid[l][r]][x]);
		lval[dpid[l][r]][x] = sdp[dpid[l][r]][x].calc(disc[x-1]);
		rval[dpid[l][r]][x] = sdp[dpid[l][r]][x].calc(disc[x]);
		return;
	}
	dp[dpid[l][r]][x].clear(); sdp[dpid[l][r]][x].clear();
	if(mx[l][r]>x) return;
	for(int lenl=(r-l+1)>>1; lenl<=(r-l+1)+1-((r-l+1)>>1); lenl++)
	{
		int mid = l+lenl-1;
		if(!(x>=a[mid].lb && x<=a[mid].rb)) {continue;} //注意此处要特判
		tmp1.clear(); tmp2.clear();
		if(mid>l)
		{
			for(int k=1; k<=x; k++)
			{
				dfs(l,mid-1,k);
				if(k<x)
				{
					tmp1.a[0] = (tmp1.a[0]+rval[dpid[l][mid-1]][k]-lval[dpid[l][mid-1]][k]+P)%P;
				}
				else
				{
					tmp1 = tmp1+sdp[dpid[l][mid-1]][k];
					tmp1.a[0] = (tmp1.a[0]-lval[dpid[l][mid-1]][k]+P)%P;
				}
			}
		}
		else
		{
			tmp1 = Polynomial(0); tmp1.a[0] = 1ll;
		}
		if(mid<r)
		{
			for(int k=0; k<=x; k++)
			{
				dfs(mid+1,r,k);
				if(k<x)
				{
					tmp2.a[0] = (tmp2.a[0]+rval[dpid[mid+1][r]][k]-lval[dpid[mid+1][r]][k]+P)%P;
				}
				else
				{
					tmp2 = tmp2+sdp[dpid[mid+1][r]][k];
					tmp2 = tmp2-dp[dpid[mid+1][r]][k];
					tmp2.a[0] = (tmp2.a[0]-lval[dpid[mid+1][r]][k]+P)%P;
				}
			}
		}
		else
		{
			tmp2 = Polynomial(0); tmp2.a[0] = 1ll;
		}
		tmp3 = tmp1*tmp2;
		dp[dpid[l][r]][x] = dp[dpid[l][r]][x]+tmp3;
	}
	sdp[dpid[l][r]][x] = prefixsum(dp[dpid[l][r]][x]);
	lval[dpid[l][r]][x] = sdp[dpid[l][r]][x].calc(disc[x-1]);
	rval[dpid[l][r]][x] = sdp[dpid[l][r]][x].calc(disc[x]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {scanf("%lld%lld",&a[i].lb,&a[i].rb); disc.push_back(a[i].lb-1); disc.push_back(a[i].rb);}
	for(int i=0; i<=n; i++)
	{
		spwx[0] = 0ll; spwy[0] = 0ll;
		for(int j=1; j<=i+1; j++)
		{
			spwx[j] = j;
			spwy[j] = (spwy[j-1]+quickpow(j,i))%P;
		}
		spw[i].interpoly(i+1,spwx,spwy);
	}
	sort(disc.begin(),disc.end()); disc.erase(unique(disc.begin(),disc.end()),disc.end());
	for(int i=1; i<=n; i++) {a[i].lb = getid(a[i].lb); a[i].rb = getid(a[i].rb);}
	nsta = 1; for(int i=0; i<disc.size(); i++)
	{
		dp[1][i] = Polynomial(0); dp[1][i].a[0] = 1ll;
		sdp[1][i] = prefixsum(dp[1][i]);
		lval[1][i] = sdp[1][i].calc(disc[i-1]);
		rval[1][i] = sdp[1][i].calc(disc[i]);
	}
	for(int i=1; i<=n; i++)
	{
		mx[i][i] = a[i].lb;
		for(int j=i+1; j<=n; j++)
		{
			mx[i][j] = max(mx[i][j-1],(int)a[j].lb);
		}
	}
	ans = 0ll;
	for(int i=1; i<disc.size(); i++)
	{
		dfs(1,n,i);
		ans = (ans+sdp[dpid[1][n]][i].calc(disc[i])-sdp[dpid[1][n]][i].calc(disc[i-1])+P)%P;
		std::cout<<i<<' '<<ans<<std::endl;
	}
	printf("%lld\n",ans);
	return 0;
}