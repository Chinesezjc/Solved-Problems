#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define INF -1
#define BLACK 0
#define WHITE 1
using namespace std;
typedef vector<int> vi;
vector<vi> adj;
vi color, ans;
int t, n, k, a, b;
void dfs(int x)
{
  if (x > n)
  {
    vi record;
    for (int i = 1; i <= n; i++)
      if (color[i] == BLACK)
        record.push_back(i);
    if (record.size() >= ans.size())
      ans.assign(record.begin(), record.end());
    return;
  }
  if (color[x] == INF)
  {
    bool dyeBlack = true;
    for (int i = 0; i < (int)adj[x].size(); i++)
    {
      int u = adj[x][i];
      if (color[u] == BLACK)
      {
        dyeBlack = false;
        break;
      }
    }
    if (dyeBlack)
    {
      color[x] = BLACK;
      dfs(x + 1);
    }
    color[x] = WHITE;
    dfs(x + 1);
    color[x] = INF;
  }
}
int main()
{
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &k);
    vector<vi>().swap(adj);
    adj.resize(n + 1);
    while (k--)
    {
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    color.resize(n + 1, INF);
    dfs(1);
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
      printf("%d%c", ans[i], i + 1 == (int)ans.size() ? '\n' : ' ');
    vi().swap(ans);
  }
  return 0;
}