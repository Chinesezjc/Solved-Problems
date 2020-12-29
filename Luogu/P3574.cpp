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
int n,t[500005],a,b,fa[500005],dp[500005],size[500005],nmsl;
vector<int> son[500005];
struct L{
    int a,b;
    bool operator < (const L &TMP)const
    {
        int A=max(a+1,b*2+1+TMP.a),B=max(TMP.a,TMP.b*2+1+a);
        return A<B?false:true;
    }
};
priority_queue<L> que;
void dfs(int now)
{
    size[now]=1;
    dp[now]=t[now];
    for(int i=0;i<(int)son[now].size();++i)
    {
        if(son[now][i]==fa[now])
        {
            swap(son[now][i],son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]]=now;
        dfs(son[now][i]);
        size[now]+=size[son[now][i]];
    }
    for(int i=0;i<(int)son[now].size();++i)
    {
        que.push((L){dp[son[now][i]],size[son[now][i]]});
    }
    int tim=0;
    while(!que.empty())
    {
        dp[now]=max(dp[now],que.top().a+tim+1);
        tim+=que.top().b*2;
        que.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>nmsl;
    for(int i=2;i<=n;++i)
    {
        cin>>t[i];
    }
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    dfs(1);
    cout<<max(dp[1],(n-1)*2+nmsl)<<endl;
    return 0;
}