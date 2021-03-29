//This Code was made by Chinese_zjc_.
#include "qq.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

#define int long long

const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;

int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}

int inv(int x) { return power(x, MOD - 2); }

signed guess(signed n, signed)
{
    std::vector<int> ans(n);
    std::pair<std::pair<int, int>, std::pair<int, int>> d;
    {
        std::vector<int> res, rk;
        int matrix[10][5];
        for (int i = 1; i <= 5; ++i)
            for (int j = i + 1; j <= 5; ++j)
                for (int k = j + 1; k <= 5; ++k)
                    res.push_back(query(i, j, k));
        for (int i = 0; i != 5; ++i)
            rk.push_back(i);
        do
        {
            memset(matrix, 0, sizeof(matrix));
            int cnt = 0;
            for (int i = 0; i != 5; ++i)
                for (int j = i + 1; j != 5; ++j)
                    for (int k = j + 1; k != 5; ++k)
                    {
                        if (rk[i] < rk[j] && rk[i] < rk[k])
                            matrix[cnt][i] = 1;
                        if (rk[j] < rk[i] && rk[j] < rk[k])
                            matrix[cnt][j] = 1;
                        if (rk[k] < rk[i] && rk[k] < rk[j])
                            matrix[cnt][k] = 1;
                        if (rk[i] > rk[j] && rk[i] > rk[k])
                            matrix[cnt][i] = 1;
                        if (rk[j] > rk[i] && rk[j] > rk[k])
                            matrix[cnt][j] = 1;
                        if (rk[k] > rk[i] && rk[k] > rk[j])
                            matrix[cnt][k] = 1;
                        ++cnt;
                    }
            std::vector<int> tmp(res);
            for (int i = 0; i != cnt; ++i)
                for (int j = 0; j != 5; ++j)
                    if (matrix[i][j])
                    {
                        for (int k = i + 1; k != cnt; ++k)
                            if (matrix[k][j])
                            {
                                int v = matrix[k][j] * inv(MOD - matrix[i][j]) % MOD;
                                tmp[k] = (tmp[k] + v * tmp[i]) % MOD;
                                for (int l = j; l != 5; ++l)
                                    if (matrix[i][l])
                                        matrix[k][l] = (matrix[k][l] + v * matrix[i][l]) % MOD;
                            }
                        break;
                    }
            bool has[5];
            memset(has, false, sizeof(has));
            for (int i = cnt; i--;)
                for (int j = 5; j--;)
                    if (matrix[i][j])
                    {
                        if (has[j])
                        {
                            tmp[i] = (tmp[i] + (MOD - matrix[i][j]) * ans[j]) % MOD;
                            matrix[i][j] = 0;
                        }
                        else
                        {
                            has[j] = true;
                            ans[j] = tmp[i] * inv(matrix[i][j]) % MOD;
                        }
                    }
            bool good = true;
            cnt = 0;
            for (int i = 0; i != 5; ++i)
                for (int j = i + 1; j != 5; ++j)
                    for (int k = j + 1; k != 5; ++k)
                        good &= (std::min({ans[i], ans[j], ans[k]}) + std::max({ans[i], ans[j], ans[k]}) == res[cnt++]);
            if (good)
                break;
        } while (std::next_permutation(rk.begin(), rk.end()));
        std::sort(rk.begin(), rk.end(), [&](const int &A, const int &B) { return ans[A] < ans[B]; });
        d = std::make_pair(std::make_pair(rk[0], rk[1]), std::make_pair(rk[1], rk[2]));
    }
    for (int i = 5; i != n; ++i)
    {
        // std::cout << d.first.first << ' ' << d.first.second << std::endl;
        int val = query(d.first.first + 1, d.first.second + 1, i + 1);
        if (val == ans[d.first.first] + ans[d.first.second])
        {
            val = query(d.second.first + 1, d.second.second + 1, i + 1);
            if (ans[d.second.first] + ans[d.second.second] < val)
                ans[i] = val - ans[d.second.first];
            else
                ans[i] = val - ans[d.second.second];
            if (ans[i] - ans[d.first.first] < ans[d.first.second] - ans[i])
                d.first = std::make_pair(d.first.first, i);
            else
                d.first = std::make_pair(i, d.first.second);
        }
        else
        {
            if (ans[d.first.first] + ans[d.first.second] < val)
                ans[i] = val - ans[d.first.first];
            else
                ans[i] = val - ans[d.first.second];
        }
    }
    // for (int i = 0; i != n; ++i)
    //     std::cout << ans[i] << " ";
    // std::cout << std::endl;
    int res = 0;
    for (int i = n; i--;)
        res = (res + ans[i]) * 233 % 998244353;
    return res;
}