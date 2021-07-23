#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7;typedef ll aN[N];aN u,v,head,to,next,ans_,d,qans,w,vis,cur;ll cnt=1,top=0,*ans=ans_;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add(ll u,ll v){//printf("%lld->%lld %lld\n",u,v,cnt+1);
next[++cnt]=head[u],to[head[u]=cnt]=v,d[u]^=1,w[cnt]=2-!u-!v;}int cmp(ll a,ll b){return to[a]<to[b];}
void dfs(ll u){rfor(ll i=cur[u];cur[u]=next[i],i;i=cur[u])if(!vis[i/2])vis[i/2]=1,dfs(to[i]),ans[++top]=i;}
void get(ll u){ll ltop=top;rfor(ll i=head[u];i;i=next[i])if(!vis[i/2]&&to[i]!=u)vis[(ans[++top]=i)/2]=1;std::sort(ans+ltop+1,ans+top+1,cmp);
ltop=top;rfor(ll i=head[u];i;i=next[i])if(!vis[i/2])vis[(ans[++top]=i)/2]=1;if((top^ltop)&1)vis[(ans[top--])/2]=0;}
int main(){
	ll n=readll(),m=readll(),l=0;rep(i,1,n)v[i]=readll()==1?0:1,u[i]=readll(),v[i]=v[i]?readll():v[i],add(u[i],v[i]),add(v[i],u[i]);
	rep(i,1,n)l+=v[i]?2:1;ll s=0;rep(i,1,m)if(d[i])s=i;if(s)add(0,s),add(s,0);memcpy(cur,head,sizeof cur);dfs(0);
	rep(i,1,top/2)std::swap(ans[i],ans[top-i+1]);printf("%lld\n",s);
	if(l&1){while(ans[0]<cnt-1)ans[top+1]=ans[0],ans++;top--;}rep(i,0,top)printf("%lld\n",ans[i]);
	rep(i,1,m)get(i);ll h=n,t=n-1;if(~l&1){ll k=0;rep(i,2,cnt)if(!vis[i/2])k=i;if(k)qans[++t]=k;}
	ll l1=0,l2=0;rep(i,1,top)l1>=l2?l2+=w[qans[++t]=ans[i]]:l1+=w[qans[--h]=ans[i]^1];rep(i,h,t)printf("%lld ",qans[i]>>1);puts("");
	rep(i,h,t)printf("%lld ",qans[i]&1);return 0;
}