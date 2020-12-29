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
#define PI 3.14159265358979323
#define INF 0x7fffffff
using namespace std;
const int per=400;
int n,m,a,b,c,d,LLL[100000/per+5],RRR[100000/per+5],tim[100000/per+5];
struct g
{
    pair<int,int> num[per+5];
    int lazytag,size;
    int rank(int l,int r,int now)
    {
        return lower_bound(num+l-1,num+r,make_pair(now-lazytag,0))-num;
    }
    void push_back(pair<int,int> tmp)
    {
        num[size++]=tmp;
    }
}h[100000/per+5];
int work(int l,int r,int v)
{
    int L=(l-1)/per+1,R=(r-1)/per+1,tmp=0;
    for(int i=L+1;i<R;++i)
    {
        tmp+=tim[i]=h[i].rank(LLL[i],RRR[i],v);
    }
    if(L==R)
    {
        for(int i=0;i<h[L].size;++i)
        {
            if(h[L].num[i].first<v-h[L].lazytag)
            {
                if(l<=h[L].num[i].second&&h[L].num[i].second<=r)
                {
                    ++tmp;
                }
            }
            else
            {
                break;
            }            
        }
        return tmp;
    }
    else
    {
        for(int i=0;i<h[L].size;++i)
        {
            if(h[L].num[i].first<v-h[L].lazytag)
            {
                if(l<=h[L].num[i].second)
                {
                    ++tmp;
                }
            }
            else
            {
                break;
            }            
        }
        for(int i=0;i<h[R].size;++i)
        {
            if(h[R].num[i].first<v-h[R].lazytag)
            {
                if(h[R].num[i].second<=r)
                {
                    ++tmp;
                }
            }
            else
            {
                break;
            }            
        }
        return tmp;
    }
}
int ask(int l,int r,int v)
{
    if(v>r-l+1)
    {
        return -1;
    }
    int L=INF,R=-INF;
    for(int i=(l-1)/per+1;i<=(r-1)/per+1;++i)
    {
        L=min(L,h[i].num[0].first+h[i].lazytag);
        R=max(R,h[i].num[h[i].size-1].first+h[i].lazytag);
        LLL[i]=1;
        RRR[i]=h[i].size;
    }
    while(L<R)
    {
        int mid=(L+R+1)>>1,tmp=work(l,r,mid);
        if(v<=tmp)
        {
            R=mid-1;
            for(int i=(l-1)/per+2;i<=(r-1)/per;++i)
            {
                RRR[i]=min(tim[i]+1,RRR[i]);
            }
        }
        else
        {
            L=mid;
            for(int i=(l-1)/per+2;i<=(r-1)/per;++i)
            {
                LLL[i]=max(tim[i]-1,LLL[i]);
            }
        }
    }
    return L;
}
void print(vector<pair<int,int> > TMP)
{
    for(int i=0;i<(int)TMP.size();++i)
    {
        cout<<TMP[i].first<<endl;
    }
}
void play(int C,vector<pair<int,int> > &A,vector<pair<int,int> > &B)
{
    int AA=0,BB=0;
    // print(A);
    // print(B);
    while(AA<(int)A.size()&&BB<(int)B.size())
    {
        // cout<<AA<<' '<<BB<<endl;
        if(A[AA]<B[BB])
        {
            h[C].num[AA+BB]=A[AA];
            ++AA;
        }
        else
        {
            h[C].num[AA+BB]=B[BB];
            ++BB;
        }
    }
    while(AA<(int)A.size())
    {
        h[C].num[AA+BB]=A[AA];
        ++AA;
    }
    while(BB<(int)B.size())
    {
        h[C].num[AA+BB]=B[BB];
        ++BB;
    }
}
void add(int l,int r,int v)
{
    int L=(l-1)/per+1,R=(r-1)/per+1;
    vector<pair<int,int> > A,B;
    for(int i=L+1;i<R;++i)
    {
        h[i].lazytag+=v;
    }
    if(L==R)
    {
        for(int i=0;i<h[L].size;++i)
        {
            if(l<=h[L].num[i].second&&h[L].num[i].second<=r)
            {
                h[L].num[i].first+=v;
                A.push_back(h[L].num[i]);
            }
            else
            {
                B.push_back(h[L].num[i]);
            }            
        }
        play(L,A,B);
    }
    else
    {
        for(int i=0;i<h[L].size;++i)
        {
            if(l<=h[L].num[i].second)
            {
                h[L].num[i].first+=v;
                A.push_back(h[L].num[i]);
            }
            else
            {
                B.push_back(h[L].num[i]);
            }            
        }
        play(L,A,B);
        A.clear();B.clear();
        for(int i=0;i<h[R].size;++i)
        {
            if(h[R].num[i].second<=r)
            {
                h[R].num[i].first+=v;
                A.push_back(h[R].num[i]);
            }
            else
            {
                B.push_back(h[R].num[i]);
            }            
        }
        play(R,A,B);
    }
}
void print()
{
    for(int i=1;i<=(n+1)>>1;++i)
    {
        for(int j=0;j<h[i].size;++j)
        {
            cout<<h[i].num[j].first<<' '<<h[i].num[j].second<<endl;
        }
    }
}
void read(int &x)
{
    x=0;
    char c=getchar();
    bool g=false;
    while('0'>c||c>'9')
    {
        (!(c^'-'))?(g=true,c=getchar()):c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^'0');
        c=getchar();
    }
    g?x=-x:0;
}
void writeln(int now)
{
    if(!now)
    {
        putchar('0');
        putchar('\n');
        return;
    }
    if(now<0)
    {
        putchar('-');
        now=-now;
    }
    char TMP[10];
    int cnt=0;
    while(now)
    {
        TMP[++cnt]=now%10;
        now/=10;
    }
    while(cnt)
    {
        putchar(TMP[cnt--]|'0');
    }
    putchar('\n');
}
signed main()
{
    ios::sync_with_stdio(false);
    // freopen("data.in","r",stdin);
    // cin>>n>>m;
    read(n);
    read(m);
    for(int i=1;i<=n;++i)
    {
        // cin>>a;
        read(a);
        h[(i-1)/per+1].push_back(make_pair(a,i));
    }
    for(int i=1;i<=(n-1)/per+1;++i)
    {
        sort(h[i].num,h[i].num+h[i].size);
    }
    for(int i=1;i<=m;++i)
    {
        // cin>>a>>b>>c>>d;
        read(a);
        read(b);
        read(c);
        read(d);
        if(a==1)
        {
            writeln(ask(b,c,d));
        }
        if(a==2)
        {
            add(b,c,d);
        }
        // print();
    }
    return 0;
}