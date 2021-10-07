// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long double eps = 1e-10;
int n, s, t, a, b;
long double dis[405][405], ans;
struct vector
{
    long double x, y;
    vector(long double x_ = 0, long double y_ = 0) : x(x_), y(y_) {}
    vector operator+() const { return *this; }
    vector operator-() const { return vector(-this->x, -this->y); }
    friend vector operator+(const vector &A, const vector &B) { return vector(A.x + B.x, A.y + B.y); }
    friend vector operator-(const vector &A, const vector &B) { return vector(A.x - B.x, A.y - B.y); }
    friend vector operator*(const long double &A, const vector &B) { return vector(A * B.x, A * B.y); }
    friend vector operator*(const vector &A, const long double &B) { return vector(A.x * B, A.y * B); }
    friend vector operator/(const vector &A, const long double &B) { return vector(A.x / B, A.y / B); }
    friend long double operator*(const vector &A, const vector &B) { return A.x * B.x + A.y * B.y; }
    friend long double operator^(const vector &A, const vector &B) { return A.x * B.y - A.y * B.x; }
    long double length() const { return std::sqrt(*this * *this); }
    friend std::istream &operator>>(std::istream &A, vector &B) { return A >> B.x >> B.y; }
    friend std::ostream &operator<<(std::ostream &A, const vector &B) { return A << '(' << B.x << ',' << B.y << ')'; }
} p[405];
void cmin(long double &A, long double B) { A = std::min(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(1);
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> s >> t >> a >> b;
        n = s * 4;
        for (int i = 0; i != s; ++i)
        {
            static long double v;
            std::cin >> p[i << 2 ^ 0] >> p[i << 2 ^ 1] >> p[i << 2 ^ 2] >> v;
            for (int j = 0; j != 3; ++j)
                if (std::abs((p[i << 2 ^ (j + 1) % 3] - p[i << 2 ^ j]) *
                             (p[i << 2 ^ (j + 2) % 3] - p[i << 2 ^ j])) < eps)
                    p[i << 2 ^ 3] = p[i << 2 ^ (j + 1) % 3] + p[i << 2 ^ (j + 2) % 3] - p[i << 2 ^ j];
            for (int j = 0; j != 4; ++j)
                for (int k = 0; k != 4; ++k)
                    if (j ^ k)
                        dis[i << 2 ^ j][i << 2 ^ k] = (p[i << 2 ^ j] - p[i << 2 ^ k]).length() * v;
            for (int j = 0; j != 4; ++j)
                for (int k = 0; k != i << 2; ++k)
                    dis[k][i << 2 ^ j] = dis[i << 2 ^ j][k] = (p[k] - p[i << 2 ^ j]).length() * t;
        }
        for (int k = 0; k != n; ++k)
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != n; ++j)
                    cmin(dis[i][j], dis[i][k] + dis[k][j]);
        ans = INFINITY;
        --a;
        --b;
        for (int i = 0; i != 4; ++i)
            for (int j = 0; j != 4; ++j)
                cmin(ans, dis[a << 2 ^ i][b << 2 ^ j]);
        std::cout << ans << std::endl;
    }
    return 0;
}