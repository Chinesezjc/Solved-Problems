//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 1e-20;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
const int e = -1;
const int map[12][12] = {{2, e, e, e, 2, e, e, 1, 2, 3, 2, e},
                         {2, 2, 2, 2, 2, e, 1, e, e, e, e, 3},
                         {1, e, 1, e, 3, e, 2, e, e, e, e, 3},
                         {1, e, 2, e, 3, e, 3, 1, 2, 3, 2, e},
                         {1, e, 3, e, 3, e, 2, e, e, e, e, e},
                         {1, e, e, e, 3, e, 1, e, e, 1, e, 0},
                         {e, e, e, e, e, e, e, e, e, e, e, e},
                         {2, e, 2, 2, e, 3, e, 3, 2, 1, 2, 3},
                         {1, e, 1, e, e, e, e, e, e, 2, e, e},
                         {2, 3, 2, e, e, 3, e, 3, e, 3, e, 2},
                         {1, e, 1, e, e, 2, e, 2, e, 2, e, e},
                         {2, e, 2, 2, e, 3, 2, 3, e, 3, e, 1}};
int find(int now, int *fa) { return now == fa[now] ? now : fa[now] = find(fa[now], fa); }
int sqr(int x) { return x * x; }
struct way
{
    bool heng[13][12], shu[12][13], sel[12][12];
    bool check() const
    {
        int fa[169], root = -1;
        for (int i = 0; i != 169; ++i)
            fa[i] = i;
        for (int i = 1; i != 12; ++i)
            for (int j = 1; j != 12; ++j)
                if (heng[i][j - 1] && heng[i][j] && shu[i - 1][j] && shu[i][j])
                    return false;
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 12; ++j)
                if (heng[i][j])
                    fa[find(i * 13 + j, fa)] = find(i * 13 + (j + 1), fa);
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 13; ++j)
                if (shu[i][j])
                    fa[find(i * 13 + j, fa)] = find((i + 1) * 13 + j, fa);
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 13; ++j)
                if (fa[i * 13 + j] != i * 13 + j)
                {
                    if (~root)
                    {
                        if (find(i * 13 + j, fa) != root)
                            return false;
                    }
                    else
                        root = find(i * 13 + j, fa);
                }
        return true;
    }
    friend bool operator==(const way &A, const way &B)
    {
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 12; ++j)
                if (A.heng[i][j] ^ B.heng[i][j])
                    return false;
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 13; ++j)
                if (A.shu[i][j] ^ B.shu[i][j])
                    return false;
        return true;
    }
    friend bool operator<(const way &A, const way &B)
    {
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 12; ++j)
                if (A.heng[i][j] ^ B.heng[i][j])
                    return B.heng[i][j];
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 13; ++j)
                if (A.shu[i][j] ^ B.shu[i][j])
                    return B.shu[i][j];
        return false;
    }
    int evaluate() const
    {
        int res = 0, tmp[12][12];
        std::vector<std::pair<int, int>> h;
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 12; ++j)
            {
                tmp[i][j] = ~map[i][j] ? llabs(heng[i][j] + heng[i + 1][j] + shu[i][j] + shu[i][j + 1] - map[i][j]) : 0;
                if (tmp[i][j])
                    h.push_back({i, j});
            }
        for (int i = 0; i != (int)h.size(); ++i)
            for (int j = 0; j != (int)h.size(); ++j)
                res += tmp[h[i].first][h[i].second] * tmp[h[j].first][h[j].second] *
                       sqr(sqr(h[i].first - h[j].first) + sqr(h[i].second - h[j].second) + 1);
        return res;
    }
    int difference(const way &B) const
    {
        int res = 0;
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 12; ++j)
                if (heng[i][j] ^ B.heng[i][j])
                    ++res;
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 13; ++j)
                if (shu[i][j] ^ B.shu[i][j])
                    ++res;
        return res;
    }
    way variation() const
    {
        way res = *this;
        static std::pair<int, int> pos[50];
        do
        {
            int tim = 50 - sqrt(Rand() * 1.0L / ULLONG_MAX * 50 * 50) - eps;
            for (int i = 0; i != tim; ++i)
            {
                pos[i] = {Rand() % 12, Rand() % 12};
                res.sel[pos[i].first][pos[i].second] ^= true;
                res.heng[pos[i].first][pos[i].second] ^= true;
                res.heng[pos[i].first + 1][pos[i].second] ^= true;
                res.shu[pos[i].first][pos[i].second] ^= true;
                res.shu[pos[i].first][pos[i].second + 1] ^= true;
            }
            if (res.check())
                return res;
            for (int i = 0; i != tim; ++i)
            {
                res.sel[pos[i].first][pos[i].second] ^= true;
                res.heng[pos[i].first][pos[i].second] ^= true;
                res.heng[pos[i].first + 1][pos[i].second] ^= true;
                res.shu[pos[i].first][pos[i].second] ^= true;
                res.shu[pos[i].first][pos[i].second + 1] ^= true;
            }
        } while (true);
    }
    void print(std::ostream &ost = std::cout) const
    {
        for (int i = 0; i != 13; ++i, ost << std::endl)
            for (int j = 0; j != 12; ++j)
                ost << heng[i][j];
        for (int i = 0; i != 12; ++i, ost << std::endl)
            for (int j = 0; j != 13; ++j)
                ost << shu[i][j];
    }
    void read(std::istream &ist = std::cin)
    {
        for (int i = 0; i != 13; ++i)
            for (int j = 0; j != 12; ++j)
            {
                static char c;
                ist >> c;
                heng[i][j] = c == '1';
            }
        for (int i = 0; i != 12; ++i)
            for (int j = 0; j != 13; ++j)
            {
                static char c;
                ist >> c;
                shu[i][j] = c == '1';
            }
    }
};
std::vector<way> s(1);
int now = INF;
signed main()
{
    std::ios::sync_with_stdio(false);
    {
        std::ifstream in("ans.txt");
        s[0].read(in);
    }
    while (now >= eps)
    {
        std::vector<int> val, rk;
        for (int j = 0; j != (int)s.size(); ++j)
            val.push_back(s[j].evaluate()), rk.push_back(j);
        std::sort(rk.begin(), rk.end(), [&](const int &A, const int &B)
                  { return val[A] < val[B]; });
        std::vector<way> nxt;
        for (int i = 0; i != 1000; ++i)
        {
            int tim = exp(Rand() * log(rk.size()) / ULLONG_MAX);
            int best = rk.back();
            for (int i = 0; i != tim; ++i)
                //     int pos =
                //         // Rand() % s.size();
                //         s.size() - sqrt(Rand() * 1.0L / ULLONG_MAX * s.size() * s.size()) - eps;
                //     // exp(Rand() * log(rk.size()) / ULLONG_MAX) - 1;
                best = std::min(best, (int)(Rand() % s.size()));
            nxt.push_back(s[rk[best]].variation());
        }
        if (now > val[rk[0]])
        {
            std::ofstream tmp("ans.txt");
            s[rk[0]].print(tmp);
            tmp << (now = val[rk[0]]) << std::endl;
            tmp.close();
        }
        for (int i = 0; i != std::min(100ll, (int)s.size()); ++i)
            nxt.emplace_back(std::move(s[i]));
        std::sort(nxt.begin(), nxt.end());
        nxt.erase(std::unique(nxt.begin(), nxt.end()), nxt.end());
        s.swap(nxt);
        std::cout << val[rk[0]] << ' ' << s.size() << std::endl;
    }
    return 0;
}