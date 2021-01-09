//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,t[500005],r,cnt,ans;
struct L{
    int v,p,fa,nxt,lst;
    bool killed;
    vector<int> son;
}a[500005];
struct G{
    int a,b,v;
}Ans[250005],tmp[10],lll[10];
bool cmp1(const L &A,const L &B)
{
    return A.v<B.v;
}
bool cmp2(const G &A,const G &B)
{
    return A.v>B.v;
}
void dfs(int now,int t)
{
    if(t*2>n)
    {
        for(int i=1;i<t;++i)
        {
            lll[i]=tmp[i];
        }
        sort(lll+1,lll+t,cmp2);
        int Tmp=0;
        for(int i=1;i<t;++i)
        {
            Tmp+=lll[i].v*i;
        }
        if(Tmp<ans)
        {
            ans=Tmp;
            for(int i=1;i<t;++i)
            {
                Ans[i]=lll[i];
            }
        }
        return;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(!(now&(1<<i))&&!(now&(1<<j))&&a[i].fa!=a[j].p)
            {
                tmp[t]=(G){a[i].p,a[j].p,a[i].v};
                dfs(now|(1<<i)|(1<<j),t+1);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].v;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].fa;
    }
    for(int i=1;i<=n;++i)
    {
        a[i].p=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;++i)
    {
        t[a[i].p]=i;
    }
    for(int i=1;i<=n;++i)
    {
        if(~a[i].fa)
        {
            a[t[a[i].fa]].son.push_back(i);
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     if(!~a[i].fa)
    //     {
    //         init(i);
    //     }
    // }
    r=n;
    for(int i=1;i<=n;++i)
    {
        a[i].nxt=i+1;
        a[i].lst=i-1;
    }
    for(int i=1;i<=n;++i)
    {
        int to=a[i].son.size()+(a[i].fa!=-1);
        if(to==n-1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(n<=10)
    {
        ans=INF;
        dfs(0,1);
        cout<<ans<<endl;
        for(int i=1;i*2<=n;++i)
        {
            cout<<Ans[i].a<<' '<<Ans[i].b<<endl;
        }
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i].killed)
        {
            continue;
        }
        while(a[r].killed)
        {
            --r;
        }
        if(a[i].fa!=a[r].p)
        {
            a[r].killed=true;
            a[i].killed=true;
            Ans[++cnt]=(G){a[i].p,a[r].p,a[i].v};
            a[a[r].lst].nxt=a[r].nxt;
            a[a[r].nxt].lst=a[r].lst;
            a[a[i].lst].nxt=a[i].nxt;
            a[a[i].nxt].lst=a[i].lst;
            r=a[r].lst;
        }
        else
        {
            int kill=a[r].lst;
            a[kill].killed=true;
            a[i].killed=true;
            Ans[++cnt]=(G){a[i].p,a[kill].p,a[i].v};
            a[a[kill].lst].nxt=a[kill].nxt;
            a[a[kill].nxt].lst=a[kill].lst;
            a[a[i].lst].nxt=a[i].nxt;
            a[a[i].nxt].lst=a[i].lst;
        }
    }
    sort(Ans+1,Ans+1+cnt,cmp2);
    for(int i=1;i<=cnt;++i)
    {
        ans+=Ans[i].v*i;
    }
    cout<<ans<<endl;
    for(int i=1;i<=cnt;++i)
    {
        cout<<Ans[i].a<<' '<<Ans[i].b<<endl;
    }
    return 0;
}