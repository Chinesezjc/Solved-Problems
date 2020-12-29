// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define max(x,y) std::max((ll)(x),(ll)(y))
#define min(x,y) std::min((ll)(x),(ll)(y))
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f,N=2145;
inline ll readll(void){
	register ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline ll iabs(ll x){
	return max(x,-x);
}
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
ll lazy_tag[N*4+9];
#define cct_(x,y) x##y
#define cct(x,y) cct_(x,y)
#define add_(c,x,y) ({register ll c=(x)+(y);c>=mod?c-mod:c;})
#define add(x...) add_(cct(add_,__LINE__),x)
struct node{
	ll min,tim,sed,sum;
	node operator+(const node&b)const{
		register ll p=min(min,b.min);
		return(node){p,(min^p?0:tim)+(b.min^p?0:b.tim),
		min((min^b.min?:p^inf)^p,min(sed,b.sed)),add(sum,b.sum)};
	}
}sgm[N*4+9];
ll y[N],lst[N],f[N],cl[N],vis[N];
inline void pushdown(register ll u){
//	printf("f=%lld %lld %lld %lld %lld %lld\n",u,sgm[u].min,sgm[u].tim,sgm[u].sed,sgm[u].sum,lazy_tag[u]);
	if(lazy_tag[u]>sgm[u].min){
		if(u<=N*2)lazy_tag[u<<1]=max(lazy_tag[u<<1],lazy_tag[u]),
		lazy_tag[u<<1|1]=max(lazy_tag[u<<1|1],lazy_tag[u]);
		sgm[u].sum=(sgm[u].sum+(lazy_tag[u]-sgm[u].min)*sgm[u].tim)%mod,
		sgm[u].min=lazy_tag[u];
	}
	lazy_tag[u]=0;
}
inline void pushup(register ll u){sgm[u]=sgm[u<<1]+sgm[u<<1|1];}
void build(ll u,ll l,ll r){
	lazy_tag[u]=0;
	if(l==r)sgm[u]=(node){f[l],(y[l]-y[l-1]),inf,f[l]*(y[l]-y[l-1])%mod};
	else{ll mid=(l+r)>>1;build(u<<1,l,mid),build(u<<1|1,mid+1,r),pushup(u);}
}
//~;'n@#[i2]$dA\-a%&/y#,=i*"Al+)Ie|^(!>.<
ll tm=0,cnt=0;
void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
//	if(u==1)printf("%lld %lld %lld %lld %lld %lld\n",u,l,r,ql,qr,c);
	pushdown(u);if(c<=sgm[u].min)return;
	if(ql<=l&&r<=qr&&c<sgm[u].sed){lazy_tag[u]=c,pushdown(u);return;}
	ll mid=(l+r)>>1;ql<=mid?update(u<<1,l,mid,ql,qr,c):pushdown(u<<1),
	qr>=mid+1?update(u<<1|1,mid+1,r,ql,qr,c):pushdown(u<<1|1),pushup(u);
}
struct point{ll x,y,c,id;void in(){x=readll(),y=readll(),c=readll();}}a[N];
struct que{ll l[N],r[N];void del(register ll x){l[r[l[x]]=r[x]]=l[x];}}q,nq;
int cmpx(const point&x,const point&y){return x.x<y.x;}
int cmpy(const point&x,const point&y){return x.y<y.y;}
int main(){
	//IO(H);
	ll n=readll(),k=readll(),L=readll(),ans=0;
	rep(i,1,n)a[i].in();std::sort(a+1,a+n+1,cmpy);
	a[0].x=a[0].y=y[a[0].id=0]=-1,a[n+1].x=a[n+1].y=y[a[n+1].id=n+1]=L;
	rep(i,1,n)y[q.r[q.r[q.l[i]=lst[a[i].c]]=i]=n+1,lst[a[i].c]=a[i].id=i]=a[i].y;
	std::sort(a+1,a+n+1,cmpx);rep(i,1,n)cl[a[i].id]=a[i].c;ll z=-~y[n]*L%mod;
//			rep(j,1,n)printf("%lld ",y[j]);
	rep(i,1,n){
		if(a[i].x^a[i-1].x){
			rfor(ll l=1,r=0;l<=n;l++){
				for(;r<n&&cnt<k;cl[++r]&&!vis[cl[r]]++&&++cnt);
				f[l]=cnt<k?L:y[r],cl[l]&&!--vis[cl[l]]&&--cnt;
			}
//			rep(j,1,n)printf("%lld ",f[j]);
//			puts("");
			build(1,1,n),nq=q;ll sum=0;
			per(j,n,i){
				sum=(sum+add(z,mod-sgm[1].sum)*(a[j+1].x-a[j].x))%mod;
//				printf("s=%lld %lld\n",sgm[1].sum,add(z,mod-sgm[1].sum)*(a[j+1].x-a[j].x));
				ll id=a[j].id;update(1,1,n,nq.l[id]+1,id,y[nq.r[id]]),nq.del(id);
			}
			ans=(sum*(a[i].x-a[i-1].x)+ans)%mod;
		}
		cl[a[i].id]=0,q.del(a[i].id);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3 6
1 2 3
2 1
2 2
2 3
1 1 1
1 2 2
2 1
*/
//	rep(i,1,n){
//		p[i].id=i;
//		if(p[i].y!=lsty)realy[++cnty]=p[i].y;
//		lsty=p[i].y;
//		p[i].y=cnty;
//	}
//	ll now=1;
//		ll lnow=now;
//		while(p[now].y==low){
//			pre[now]=
//			lst[p[now].c]=now;
//			now++;
//		}
//
//	std::sort(p+1,p+n+1,cmpy);
//	rep(low,1,cnty){
//		rep(up,1,low){
//
//		}
//	}