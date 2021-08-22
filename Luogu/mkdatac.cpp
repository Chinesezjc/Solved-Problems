#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int y[max_n];
int main()
{
    freopen("data.in","w",stdout);
    int n=1e5;
    printf("%d\n",n);
    for(int i=1;i<=n;++i)
        y[i]=i;
    srand(666);
    random_shuffle(y+1,y+n+1);
    for(int i=1;i<=n;++i)
        printf("%d %d\n",0,y[i]);
    return 0;
}