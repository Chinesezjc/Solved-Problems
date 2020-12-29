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
int n,m,v[2][1000005],tmp[2][1000005];
vector<char> a[1000005];
char x;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n>=4&&m>=4)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }
    if(n<2||m<2)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==2)
    {
        for(int i=1;i<m;++i)
        {
            v[0][i]=a[1][i]^a[1][i+1]^a[2][i]^a[2][i+1];
        }
        int ans1=0,ans2=0;
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
        }
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]==0)
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
        }
        tmp[0][1]^=1;
        ++ans2;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i])
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[1][i]^=1;
            }
        }
        cout<<min(ans1,ans2)<<endl;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<n;++i)
        {
            v[0][i]=a[i][1]^a[i][2]^a[i+1][1]^a[i+1][2];
        }
        int ans1=0,ans2=0;
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
        }
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]==0)
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
        }
        tmp[0][1]^=1;
        ++ans2;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i])
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[1][i]^=1;
            }
        }
        cout<<min(ans1,ans2)<<endl;
        return 0;
    }
    if(n==3)
    {
        for(int i=1;i<m;++i)
        {
            v[0][i]=a[1][i]^a[2][i]^a[1][i+1]^a[2][i+1];
            v[1][i]=a[2][i]^a[3][i]^a[2][i+1]^a[3][i+1];
        }
        int ans1=0,ans2=0,ans3=0,ans4=0;
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans2;
        tmp[0][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans2;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans3;
        tmp[1][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans3;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans3;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans3;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans4;
        tmp[0][1]^=1;
        tmp[1][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans4;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans4;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans4;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        cout<<min(min(ans1,ans2),min(ans3,ans4))<<endl;
        return 0;
    }
    if(m==3)
    {
        for(int i=1;i<n;++i)
        {
            v[0][i]=a[i][1]^a[i][2]^a[i+1][1]^a[i+1][2];
            v[1][i]=a[i][2]^a[i][3]^a[i+1][2]^a[i+1][3];
        }
        int ans1=0,ans2=0,ans3=0,ans4=0;
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans1;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans2;
        tmp[0][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans2;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans2;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans3;
        tmp[1][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans3;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans3;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans3;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        for(int i=1;i<m;++i)
        {
            tmp[0][i]=v[0][i];
            tmp[1][i]=v[1][i];
        }
        ++ans4;
        tmp[0][1]^=1;
        tmp[1][1]^=1;
        for(int i=1;i<m;++i)
        {
            if(tmp[0][i]&tmp[1][i])
            {
                continue;
            }
            else if(tmp[0][i])
            {
                ++ans4;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
            else if(tmp[1][i])
            {
                ++ans4;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
            }
            else
            {
                ++ans4;
                tmp[0][i]^=1;
                tmp[0][i+1]^=1;
                tmp[1][i]^=1;
                tmp[1][i+1]^=1;
            }
        }
        cout<<min(min(ans1,ans2),min(ans3,ans4))<<endl;
        return 0;
    }
    return 0;
}