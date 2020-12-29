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
int n,k,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    ans=n*k;
    for(int R=n;R;)
    {
        int l=1,r=R,i=k/R;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(k/mid==i)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans-=i*(R-l+1)*(l+R)/2;
        R=l-1;
        // cout<<i<<' '<<l<<' '<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}