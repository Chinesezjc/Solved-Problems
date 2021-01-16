#include <bits/stdc++.h>
using namespace std;
inline int read()
{ //读优
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
int n, m, s, t;
struct Edge
{
    int u, v, w, nxt;
} e[120010];
int head[4010], cnt = 1; //注意：cnt必须从1开始，因为加边是n和n+1，偶数和偶数+1可以通过异或转化，具体请自行推导
inline void add(int u, int v, int w)
{ //前向星加边
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int dis[4010];
int bfs()
{
    queue<int> q; //广搜队列
    q.push(s);
    memset(dis, -1, sizeof(dis)); //所有编号赋初值
    dis[s] = 0;                   //初始原点编号，让其可以朝下分层
    while (!q.empty())
    {
        int u = q.front();
        q.pop(); //取出队首
        for (int i = head[u]; i; i = e[i].nxt)
        {
            if (e[i].w > 0 && dis[e[i].v] == -1)
            {                             //如果此点可以流并且它没有被编号过
                dis[e[i].v] = dis[u] + 1; //分层编号
                q.push(e[i].v);           //入队
                if (e[i].v == t)
                    return 1; //如果将汇点编完号，返回，示意dinic继续找增广
            }
        }
    }
    return 0; //找不到一条可行流，示意dinic返回
}
int dfs(int x, int f)
{
    if (x == t || f == 0)
        return f; //如果搜到了增广路或者没有流量走不下去
    int used = 0; //定义已经流出的流量
    for (int i = head[x]; i; i = e[i].nxt)
    {
        if (e[i].w > 0 && dis[e[i].v] == dis[x] + 1)
        {                                        //如果此边能走通并且编号正确（根据dinic，只有是下一编号才能走通）
            int k = dfs(e[i].v, min(e[i].w, f)); //向下流，注意处理流量!!!一定要二者最小的！
            if (k == 0)
                continue; //无法流通，继续处理下一条边
            used += k;
            f -= k; //减少剩余流量，增加流出流量
            e[i].w -= k;
            e[i ^ 1].w += k; //对正向弧和反向弧做流量处理
            if (f == 0)
                break; //剩余流量为0，结束
        }
    }
    if (used == 0)
        dis[x] = -1; //无法下流，使其退出分层，下次不用再走，否则浪费效率
    return used;     //返回可行流的最大流量
}
int dinic()
{
    int flow = 0; //最大流
    while (bfs())
        flow += dfs(s, 0x7fffffff); //加上每次增广可继续下流的流量
    return flow;
}
int dfn[4010], low[4010], vis[4010], scc[4010], num, cntt;
stack<int> st;
void tarjan(int u)
{ //tarjan模板，判scc分量，见模板题，不做详细解释
    st.push(u);
    vis[u] = 1;
    dfn[u] = low[u] = ++cntt;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        if (e[i].w == 0)
            continue; //注意,满流时无法继续，是本题的关键点
        if (dfn[e[i].v] == 0)
        {
            tarjan(e[i].v);
            low[u] = min(low[u], low[e[i].v]);
        }
        else if (vis[e[i].v] == 1)
            low[u] = min(dfn[e[i].v], low[u]);
    }
    if (dfn[u] == low[u])
    {
        ++num;
        while (1)
        {
            int top = st.top();
            st.pop();
            vis[top] = 0;
            scc[top] = num;
            if (top == u)
                break;
        }
    }
}
int main()
{
    n = read();
    m = read();
    s = read();
    t = read();
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        add(u, v, w);
        add(v, u, 0); //加边，正向弧和反向弧
    }
    int flow = dinic(); //尽管flow并没有用，但调试较为方便
    for (int i = 1; i <= n; ++i)
        if (scc[i] == 0)
            tarjan(i); //如果没有判过scc，跑一遍，求出它属于的联通块
    //判断方法和公式见前面
    for (int i = 2; i < cnt; i += 2)
    { //这样才能跳到每一条正向边
        int u = e[i].u, v = e[i].v;
        if (e[i].w == 0 && scc[u] != scc[v])
        { //记得判断满流
            printf("1 ");
            if (scc[u] == scc[s] && scc[v] == scc[t])
                printf("1");
            else
                printf("0");
        }
        else
            printf("0 0");
        printf("\n");
    }
    return 0;
}