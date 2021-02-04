//It is made by HolseLee on 28th Aug 2018
//Luogu.org P3273
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Max(a, b) (a) > (b) ? (a) : (b)
using namespace std;

const int N = 3e5 + 7;
int n, a[N], m, allsign, root;
struct Leftist
{
    int ch[N][2], val[N], sign[N], fa[N], dis[N];

    void clear(int x)
    {
        ch[x][0] = ch[x][1] = fa[x] = 0;
    }

    int sum(int x)
    {
        int ret = 0;
        while (x = fa[x])
            ret += sign[x];
        return ret;
    }

    void pushdown(int x)
    {
        int ul = ch[x][0], ur = ch[x][1];
        if (ul)
            val[ul] += sign[x], sign[ul] += sign[x];
        if (ur)
            val[ur] += sign[x], sign[ur] += sign[x];
        sign[x] = 0;
    }

    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (val[x] < val[y])
            swap(x, y);
        pushdown(x);
        int &ul = ch[x][0], &ur = ch[x][1];
        ur = merge(ur, y);
        fa[ur] = x;
        if (dis[ur] > dis[ul])
            swap(ul, ur);
        dis[x] = dis[ur] + 1;
        return x;
    }

    int find(int x)
    {
        while (fa[x])
            x = fa[x];
        return x;
    }

    int delet(int x)
    {
        pushdown(x);
        int fx = fa[x];
        int ka = merge(ch[x][0], ch[x][1]);
        fa[ka] = fx;
        if (fx)
            ch[fx][x == ch[fx][1]] = ka;
        while (fx)
        {
            if (dis[ch[fx][0]] < dis[ch[fx][1]])
                swap(ch[fx][0], ch[fx][1]);
            if (dis[fx] == dis[ch[fx][1]] + 1)
                return root;
            dis[fx] = dis[ch[fx][1]] + 1;
            ka = fx;
            fx = fa[fx];
        }
        return ka;
    }

    int add_point(int x, int v)
    {
        int fx = find(x);
        if (fx == x)
        {
            if (ch[x][0] + ch[x][1] == 0)
            {
                val[x] += v;
                return x;
            }
            else
            {
                if (ch[x][0])
                    fx = ch[x][0];
                else
                    fx = ch[x][1];
            }
        }
        delet(x);
        val[x] += v + sum(x);
        clear(x);
        return merge(find(fx), x);
    }

    int build()
    {
        queue<int> t;
        for (int i = 1; i <= n; ++i)
            t.push(i);
        int x, y, z;
        while (t.size() > 1)
        {
            x = t.front();
            t.pop();
            y = t.front();
            t.pop();
            z = merge(x, y);
            t.push(z);
        }
        return t.front();
    }
} T, H;

void read(int &x)
{
    x = 0;
    char ch = getchar();
    bool flag = false;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = true;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    flag ? x *= (-1) : 1;
}

int main()
{
    read(n);
    T.dis[0] = H.dis[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        T.val[i] = H.val[i] = a[i];
    }
    root = H.build();
    read(m);
    char op[3];
    int x, y, fx, fy, temp;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", op);
        if (op[0] == 'A')
        {
            switch (op[1])
            {
            case '1':
                read(x), read(y);
                root = H.delet(T.find(x));
                temp = T.add_point(x, y);
                H.val[temp] = T.val[temp];
                H.clear(temp);
                root = H.merge(root, temp);
                break;

            case '2':
                read(x), read(y);
                fx = T.find(x);
                root = H.delet(fx);
                T.val[fx] += y;
                T.sign[fx] += y;
                H.val[fx] = T.val[fx];
                H.clear(fx);
                root = H.merge(root, fx);
                break;

            case '3':
                read(y);
                allsign += y;
                break;
            }
        }
        else if (op[0] == 'F')
        {
            switch (op[1])
            {
            case '1':
                read(x);
                printf("%d\n", T.val[x] + allsign + T.sum(x));
                break;

            case '2':
                read(x);
                printf("%d\n", T.val[T.find(x)] + allsign);
                break;

            case '3':
                printf("%d\n", H.val[root] + allsign);
                break;
            }
        }
        else
        {
            read(x), read(y);
            fx = T.find(x), fy = T.find(y);
            if (fx == fy)
                continue;
            temp = T.merge(fx, fy);
            if (temp == fx)
                root = H.delet(fy);
            else
                root = H.delet(fx);
        }
    }
    return 0;
}