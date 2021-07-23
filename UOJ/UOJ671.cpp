// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
typedef __uint128_t u128;
std::istream &operator>>(std::istream &in, u128 &res)
{
    static char buf[100];
    in >> buf;
    res = 0;
    for (int i = 0; buf[i]; ++i)
        res = res << 4 | (buf[i] <= '9' ? buf[i] - '0' : buf[i] - 'a' + 10);
    return in;
}
std::ostream &operator<<(std::ostream &out, const u128 &res)
{
    if (res >= 16)
        out << res / 16;
    out.put(res % 16 >= 10 ? 'a' + res % 16 - 10 : '0' + res % 16);
    return out;
}
int n, m;
u128 a[300005], Pow[128];
std::stringstream res;
const int B = 600, D = 7, D2 = (1 << D) - 1;
struct node
{
    std::pair<u128, int> s[B];
    int l, r, app[128 / D + 1][1 << D];
    u128 tag, sum;
    void Init(int l_, int r_)
    {
        l = l_;
        r = r_;
        for (int i = l; i <= r; ++i)
            s[i - l] = {a[i], i};
        std::sort(s, s + B);
        for (int i = 0; i != B; ++i)
            for (int j = 0; j * D < 128; ++j)
                ++app[j][s[i].first >> j * D & D2];
        for (int i = 0; i != B; ++i)
            sum += s[i].first;
        tag = -1;
    }
    void Div(u128 V, int L, int R)
    {
        if (R < l || r < L || !s[B - 1].first)
            return;
        if (tag != u128(-1))
        {
            for (int i = 0; i != B; ++i)
                s[i].first &= tag;
            tag = -1;
            std::sort(s, s + B);
        }
        if (L <= l && r <= R)
        {
            for (int i = B; i-- && s[i].first;)
            {
                sum -= s[i].first;
                for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                    --app[j][s[i].first >> j * D & D2];
                s[i].first /= V;
                for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                    ++app[j][s[i].first >> j * D & D2];
                sum += s[i].first;
            }
        }
        else
        {
            for (int i = 0; i != B; ++i)
                if (L <= s[i].second && s[i].second <= R)
                {
                    sum -= s[i].first;
                    for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                        --app[j][s[i].first >> j * D & D2];
                    s[i].first /= V;
                    for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                        ++app[j][s[i].first >> j * D & D2];
                    sum += s[i].first;
                }
            std::sort(s, s + B);
        }
    }
    void And(u128 V, int L, int R)
    {
        if (R < l || r < L || !s[B - 1].first)
            return;
        if (L <= l && r <= R)
        {
            if ((tag & V) == tag)
                return;
            tag &= V;
            for (int i = 0; i * D < 128 && Pow[i * D] <= s[B - 1].first; ++i)
            {
                int tmp = V >> i * D & D2;
                if (tmp == D2)
                    continue;
                for (int j = 1; j != 1 << D; ++j)
                {
                    if ((tmp & j) == j || !app[i][j])
                        continue;
                    sum -= Pow[i * D] * app[i][j] * (j - (tmp & j));
                    app[i][j & tmp] += app[i][j];
                    app[i][j] = 0;
                }
            }
        }
        else
        {
            if (tag != u128(-1))
            {
                for (int i = 0; i != B; ++i)
                    s[i].first &= tag;
                tag = -1;
                std::sort(s, s + B);
            }
            for (int i = 0; i != B; ++i)
                if (L <= s[i].second && s[i].second <= R)
                {
                    sum -= s[i].first;
                    for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                        --app[j][s[i].first >> j * D & D2];
                    s[i].first &= V;
                    for (int j = 0; j * D < 128 && Pow[j * D] <= s[i].first; ++j)
                        ++app[j][s[i].first >> j * D & D2];
                    sum += s[i].first;
                }
            std::sort(s, s + B);
        }
    }
    u128 Sum(int L, int R)
    {
        if (R < l || r < L || !s[B - 1].first)
            return 0;
        if (L <= l && r <= R)
            return sum;
        else
        {
            if (tag != u128(-1))
            {
                for (int i = 0; i != B; ++i)
                    s[i].first &= tag;
                tag = -1;
                std::sort(s, s + B);
            }
            u128 res = 0;
            for (int i = 0; i != B; ++i)
                if (L <= s[i].second && s[i].second <= R)
                    res += s[i].first;
            return res;
        }
    }
} b[300005 / B + 5];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    Pow[0] = 1;
    for (int i = 1; i != 128; ++i)
        Pow[i] = Pow[i - 1] * 2;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 0; i * B < n; ++i)
        b[i].Init(i * B + 1, i * B + B);
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r;
        static u128 sum, v;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> l >> r >> v;
            if (v != 1)
                for (int j = 0; j * B < n; ++j)
                    b[j].Div(v, l, r);
            break;
        case 2:
            std::cin >> l >> r >> v;
            if (v != u128(-1))
                for (int j = 0; j * B < n; ++j)
                    b[j].And(v, l, r);
            break;
        case 3:
            std::cin >> l >> r;
            sum = 0;
            for (int j = 0; j * B < n; ++j)
                sum += b[j].Sum(l, r);
            res << sum << std::endl;
            break;
        }
    }
    // std::cout << clock() << std::endl;
    std::cout << res.str();
    return 0;
}