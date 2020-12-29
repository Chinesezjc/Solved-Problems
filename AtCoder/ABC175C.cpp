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
int X,K,D;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>X>>K>>D;
    int cnt=min(abs(X)/D,K);
    if(X<0)
    {
        X+=cnt*D;
    }
    if(X>0)
    {
        X-=cnt*D;
    }
    K-=cnt;
    K&=1;
    if(K&1)
    {
        if(X>0)
        {
            X-=D;
        }
        else
        {
            X+=D;
        }
    }
    cout<<abs(X)<<endl;
    return 0;
}