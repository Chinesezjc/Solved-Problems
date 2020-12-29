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
int n,m,p,today[10],ans;
bool possible;
map<string,vector<pair<string,int> > > sayings;
//types:
//0:XXX is guilty.
//1:XXX is not guilty.
//2:Today is XXX.
string name[25],tmp,f,l;
map<string,int> names;
map<string,int> date;
int numbers(int now)
{
    int res=0;
    for(int i=0;1<<i<=now;++i)
    {
        if((1<<i)&now)
        {
            ++res;
        }
    }
    return res;
}
pair<int,int> work(int now)
{
    int today[10],guilty[25];
    memset(today,false,sizeof(today));
    memset(guilty,false,sizeof(guilty));
    for(int i=1;i<=m;++i)
    {
        if(now&(1<<i>>1))
        {
            for(auto j:sayings[name[i]])
            {
                if(j.second==0)
                {
                    if(guilty[names[j.first]]==1)
                    {
                        return make_pair(0,0);
                    }
                    guilty[names[j.first]]=-1;
                }
                if(j.second==1)
                {
                    if(guilty[names[j.first]]==-1)
                    {
                        return make_pair(0,0);
                    }
                    guilty[names[j.first]]=1;
                }
                if(j.second==2)
                {
                    if(today[date[j.first]]==1)
                    {
                        return make_pair(0,0);
                    }
                    today[date[j.first]]=-1;
                }
            }
        }
        else
        {
            for(auto j:sayings[name[i]])
            {
                if(j.second==0)
                {
                    if(guilty[names[j.first]]==-1)
                    {
                        return make_pair(0,0);
                    }
                    fill(guilty+1,guilty+1+m,-1);
                    guilty[names[j.first]]=1;
                }
                if(j.second==1)
                {
                    if(guilty[names[j.first]]==1)
                    {
                        return make_pair(0,0);
                    }
                    guilty[names[j.first]]=-1;
                }
                if(j.second==2)
                {
                    if(today[date[j.first]]==-1)
                    {
                        return make_pair(0,0);
                    }
                    fill(today+1,today+8,-1);
                    today[date[j.first]]=1;
                }
            }
        }
    }
    int res=0,no=0;;
    for(int i=1;i<=m;++i)
    {
        if(guilty[i]==1)
        {
            if(res)
            {
                cout<<"Cannot Determine"<<endl;
                exit(0);
            }
            res=i;
        }
        if(guilty[i]==-1)
        {
            ++no;
        }
    }
    if(no==m-1)
    {
        for(int i=1;i<=m;++i)
        {
            if(guilty[i]==0)
            {
                return make_pair(1,i);
            }
        }
    }
    return make_pair(1,res);
}
signed main()
{
    ios::sync_with_stdio(false);
    date["Monday"]=1;
    date["Tuesday"]=2;
    date["Wednesday"]=3;
    date["Thursday"]=4;
    date["Friday"]=5;
    date["Saturday"]=6;
    date["Sunday"]=7;
    cin>>m>>n>>p;
    for(int i=1;i<=m;++i)
    {
        cin>>name[i];
        names[name[i]]=i;
    }
    // cout<<"NMSL"<<endl;
    for(int i=1;i<=p;++i)
    {
        cin>>f;
        f.pop_back();
        cin>>l;
        cin>>tmp;
        if(l=="I")
        {
            if(tmp=="am")
            {
                cin>>tmp;
                if(tmp=="guilty.")
                {
                    sayings[f].push_back(make_pair(f,0));
                    getline(cin,tmp);
                    continue;
                }
                if(tmp=="not")
                {
                    cin>>tmp;
                    if(tmp=="guilty.")
                    {
                        sayings[f].push_back(make_pair(f,1));
                        getline(cin,tmp);
                        continue;
                    }
                }
            }
        }
        if(names[l])
        {
            if(tmp=="is")
            {
                cin>>tmp;
                if(tmp=="guilty.")
                {
                    sayings[f].push_back(make_pair(l,0));
                    getline(cin,tmp);
                    continue;
                }
                if(tmp=="not")
                {
                    cin>>tmp;
                    if(tmp=="guilty.")
                    {
                        sayings[f].push_back(make_pair(l,1));
                        getline(cin,tmp);
                        continue;
                    }
                }
            }
        }
        if(l=="Today")
        {
            if(tmp=="is")
            {
                cin>>l;
                l.pop_back();
                if(date[l])
                {
                    sayings[f].push_back(make_pair(l,2));
                    getline(cin,tmp);
                    continue;
                }
            }
        }
        getline(cin,tmp);
    }
    for(int i=0;i<1<<m;++i)
    {
        if(numbers(i)==n)
        {
            pair<int,int> res=work(i);
            if(res.first)
            {
                possible=true;
            }
            if(ans==0)
            {
                ans=res.second;
            }
            // cout<<res<<endl;
            if(res.second&&ans!=res.second)
            {
                cout<<"Cannot Determine"<<endl;
                return 0;
            }
        }
    }
    if(!possible)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<(ans?name[ans]:"Cannot Determine")<<endl;
    return 0;
}