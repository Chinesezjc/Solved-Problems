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
// This Code was made by Chinese_zjc_.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

// Please use at least C++11.

#if __cplusplus < 201402L
#define constexpr
#endif

namespace zjcSTL
{
    const double eps = 1e-10;
    const double INF = 1e50;
    template <class __Tp>
    class complex
    {
    public:
        __Tp x, y;
        constexpr complex()
        {
        }
        constexpr complex(const __Tp &A)
        {
            x = A;
        }
        constexpr complex(const __Tp &A, const __Tp &B)
        {
            x = A;
            y = B;
        }
        complex operator+(const complex &__Val) const noexcept
        {
            return {x + __Val.x, y + __Val.y};
        }
        complex operator-(const complex &__Val) const noexcept
        {
            return {x - __Val.x, y - __Val.y};
        }
        complex operator*(const complex &__Val) const noexcept
        {
            return {x * __Val.x - y * __Val.y, x * __Val.y + y * __Val.x};
        }
        complex operator/(const complex &__Val) const noexcept
        {
            return {(x * __Val.x + y * __Val.y) / (__Val.x * __Val.x - __Val.y * __Val.y),
                    (__Val.x * y - x * __Val.y) / (__Val.x * __Val.x - __Val.y * __Val.y)};
        }
        complex &operator+=(const complex &__Val) noexcept
        {
            return *this = *this + __Val;
        }
        complex &operator-=(const complex &__Val) noexcept
        {
            return *this = *this - __Val;
        }
        complex &operator*=(const complex &__Val) noexcept
        {
            return *this = *this * __Val;
        }
        complex &operator/=(const complex &__Val) noexcept
        {
            return *this = *this / __Val;
        }
        friend complex conj(const complex &__Val) noexcept
        {
            return complex(__Val.x, -__Val.y);
        }
        friend std::istream &operator>>(std::istream &ist, complex &__Val)
        {
            return ist >> __Val.x >> __Val.y;
        }
        friend std::ostream &operator<<(std::ostream &ost, const complex &__Val)
        {
            return ost << '(' << __Val.x << ',' << __Val.y << ')';
        }
    };
    template <typename __Tp>
    complex<__Tp> polar(const __Tp &__rho, const __Tp &__theta) noexcept
    {
        assert(__rho >= 0);
        return complex<__Tp>(__rho * cos(__theta), __rho * sin(__theta));
    }
    class FFT_data
    {
    public:
        bool init_for_FFT = false;
        complex<double> w[1 << 23 | 1];
        int rev[1 << 23];
        void init() noexcept
        {
            init_for_FFT = true;
            std::vector<complex<long double>> TMP(1 << 23);
            rev[1] = 1 << 22;
            for (int i = 2; i < 1 << 23; ++i)
            {
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << 22);
            }
            TMP[0] = {1, 0};
            for (int i = 1 << 22; i; i >>= 1)
            {
                complex<long double> x = polar(1.0l, acos(-1.0l) / ((1 << 22) / i) * 1.0l);
                for (int j = 0; j < 1 << 23; j += i << 1)
                {
                    TMP[j | i] = TMP[j] * x;
                }
            }
            for (int i = 0; i < 1 << 23; ++i)
            {
                w[i] = {(double)TMP[i].x, (double)TMP[i].y};
            }
        }
    };
    FFT_data data;
    template <size_t base = 10>
    class bigint
    {
    private:
        std::vector<long long> number;
        bool mark;
        void shrink_to_fit() noexcept
        {
            while (!(number.empty() || number.back()))
            {
                number.pop_back();
            }
            if (number.empty())
            {
                mark = false;
            }
        }

    public:
        class iterator
        {
        private:
            std::vector<long long>::iterator Iter;

        public:
            constexpr iterator() noexcept
            {
            }
            iterator(const std::vector<long long>::iterator &__Val) noexcept
            {
                Iter = __Val;
            }
            iterator operator++() noexcept
            {
                return ++Iter;
            }
            iterator operator++(int) noexcept
            {
                return Iter++;
            }
            iterator operator--() noexcept
            {
                return --Iter;
            }
            iterator operator--(int) noexcept
            {
                return Iter--;
            }
            bool operator==(const iterator &__Val) const noexcept
            {
                return Iter == __Val.Iter;
            }
            bool operator!=(const iterator &__Val) const noexcept
            {
                return Iter != __Val.Iter;
            }
            long long &operator*() const noexcept
            {
                return *Iter;
            }
        };
        class reverse_iterator
        {
        private:
            std::vector<long long>::reverse_iterator Iter;

        public:
            constexpr reverse_iterator() noexcept
            {
            }
            reverse_iterator(const std::vector<long long>::reverse_iterator &__Val) noexcept
            {
                Iter = __Val;
            }
            reverse_iterator operator++() noexcept
            {
                return ++Iter;
            }
            reverse_iterator operator++(int) noexcept
            {
                return Iter++;
            }
            reverse_iterator operator--() noexcept
            {
                return --Iter;
            }
            reverse_iterator operator--(int) noexcept
            {
                return Iter--;
            }
            bool operator==(const reverse_iterator &__Val) const noexcept
            {
                return Iter == __Val.Iter;
            }
            bool operator!=(const reverse_iterator &__Val) const noexcept
            {
                return Iter != __Val.Iter;
            }
            long long &operator*() const noexcept
            {
                return *Iter;
            }
        };
        iterator begin() noexcept
        {
            return number.begin();
        }
        iterator end() noexcept
        {
            return number.end();
        }
        reverse_iterator rbegin() noexcept
        {
            return number.rbegin();
        }
        reverse_iterator rend() noexcept
        {
            return number.rend();
        }
        constexpr bigint() noexcept
        {
            number.clear();
            mark = false;
        }
        bigint(const long long &__Val) noexcept
        {
            long long v = __Val;
            mark = v < 0;
            v = v < 0 ? -v : v;
            while (v)
            {
                number.push_back(v % base);
                v /= base;
            }
        }
        bigint(const std::string &__Val) noexcept
        {
            number.clear();
            mark = false;
            std::string tmp = __Val;
            std::reverse(tmp.begin(), tmp.end());
            if (tmp.back() == '-')
            {
                mark = true;
                tmp.pop_back();
            }
            if (base <= 36)
            {
                for (int i = 0; i < (int)tmp.length(); ++i)
                {
                    number.push_back(tmp[i] <= '9' ? tmp[i] & 15 : (tmp[i] & 31) + 9);
                }
            }
            else if (pow(10, (int)log10(base)) == base)
            {
                int len = log10(base), v = 1;
                for (int i = 0; i < (int)tmp.length(); ++i)
                {
                    if (i % len == 0)
                    {
                        number.push_back((tmp[i] & 15) * (v = 1));
                    }
                    else
                    {
                        number.back() += (tmp[i] & 15) * (v *= 10);
                    }
                }
            }
            shrink_to_fit();
        }
        void clear() noexcept
        {
            number.clear();
            mark = false;
        }
        bool empty() const noexcept
        {
            return !mark && number.empty();
        }
        bool operator<(const bigint &__Val) const noexcept
        {
            if (mark != __Val.mark)
            {
                return mark && !__Val.mark;
            }
            if (mark)
            {
                return -__Val < -*this;
            }
            if (empty() ^ __Val.empty())
            {
                return empty();
            }
            if (empty() && __Val.empty())
            {
                return false;
            }
            if (size() != __Val.size())
            {
                return size() < __Val.size();
            }
            for (int i = size() - 1; i >= 0; --i)
            {
                if (number[i] != __Val.number[i])
                {
                    return number[i] < __Val.number[i];
                }
            }
            return false;
        }
        bool operator==(const bigint &__Val) const noexcept
        {
            return mark == __Val.mark && number == __Val.number;
        }
        bool operator>(const bigint &__Val) const noexcept
        {
            return __Val < *this;
        }
        bool operator<=(const bigint &__Val) const noexcept
        {
            return *this == __Val || *this < __Val;
        }
        bool operator>=(const bigint &__Val) const noexcept
        {
            return *this == __Val || __Val < *this;
        }
        bool operator!=(const bigint &__Val) const noexcept
        {
            return !(*this == __Val);
        }
        size_t size() const noexcept
        {
            return number.size();
        }
        bigint operator-() const noexcept
        {
            if (empty())
            {
                return *this;
            }
            bigint res = *this;
            res.mark ^= true;
            return res;
        }
        bigint operator+(const bigint &__Val) const noexcept
        {
            if (empty())
            {
                return __Val;
            }
            if (__Val.empty())
            {
                return *this;
            }
            if (mark)
            {
                return __Val - (-*this);
            }
            if (__Val.mark)
            {
                return *this - (-__Val);
            }
            bigint res;
            res.number.assign(std::max(size(), __Val.size()), 0);
            for (int i = 0; i < (int)size(); ++i)
            {
                res.number[i] += number[i];
            }
            for (int i = 0; i < (int)__Val.size(); ++i)
            {
                res.number[i] += __Val.number[i];
            }
            for (int i = 1; i < (int)res.size(); ++i)
            {
                if (res.number[i - 1] >= base)
                {
                    res.number[i - 1] -= base;
                    ++res.number[i];
                }
            }
            if (res.number.back() >= base)
            {
                res.number.back() -= base;
                res.number.push_back(1);
            }
            return res;
        }
        bigint operator-(const bigint &__Val) const noexcept
        {
            if (empty())
            {
                return -__Val;
            }
            if (__Val.empty())
            {
                return *this;
            }
            if (mark)
            {
                return -(-*this + __Val);
            }
            if (__Val.mark)
            {
                return *this + __Val;
            }
            if (*this < __Val)
            {
                return -(__Val - *this);
            }
            bigint res = *this;
            for (int i = 0; i < (int)__Val.size(); ++i)
            {
                if (res.number[i] < __Val.number[i])
                {
                    res.number[i] += base;
                    --res.number[i + 1];
                }
                res.number[i] -= __Val.number[i];
            }
            for (int i = __Val.size(); res.number[i] < 0; ++i)
            {
                res.number[i] += base;
                --res.number[i + 1];
            }
            res.shrink_to_fit();
            return res;
        }
        bigint operator*(const bigint &__Val) const noexcept
        {
            if (empty() || __Val.empty())
            {
                return 0;
            }
            bigint res;
            if (size() + __Val.size() <= 512)
            {
                res.mark = mark ^ __Val.mark;
                res.number.assign(size() + __Val.size(), 0);
                for (int i = 0; i < (int)size(); ++i)
                {
                    for (int j = 0; j < (int)__Val.size(); ++j)
                    {
                        res.number[i + j] += number[i] * __Val.number[j];
                    }
                }
                for (int i = 1; i < (int)res.size(); ++i)
                {
                    if (res.number[i - 1] >= base)
                    {
                        res.number[i] += res.number[i - 1] / base;
                        res.number[i - 1] %= base;
                    }
                }
                res.shrink_to_fit();
            }
            else if (size() + __Val.size() <= 100000)
            {
                int len = std::min(size(), __Val.size()) >> 1;
                bigint AC = (*this >> len) * (__Val >> len);
                bigint BD = (*this & len) * (__Val & len);
                res = (AC << (len << 1)) +
                      ((((*this >> len) + (*this & len)) * ((__Val >> len) + (__Val & len)) - AC - BD) << len) +
                      BD;
            }
            else if (size() + __Val.size() <= 40000000)
            {
                res.mark = mark ^ __Val.mark;
                if (!data.init_for_FFT)
                {
                    data.init();
                }
                int len = 32 - __builtin_clz(size() + __Val.size()), siz = 1 << len;
                std::vector<complex<double>> A(siz, 0), B;
                for (int i = 0; i < (int)size(); ++i)
                {
                    A[i].x = number[i];
                }
                for (int i = 0; i < (int)__Val.size(); ++i)
                {
                    A[i].y = __Val.number[i];
                }
                for (int i = 0; i < siz; ++i)
                {
                    if (i < (data.rev[i] >> (23 - len)))
                    {
                        std::swap(A[i], A[data.rev[i] >> (23 - len)]);
                    }
                }
                for (int k = 1; k < siz; k <<= 1)
                {
                    int l = (1 << 22) / k;
                    for (int i = 0; i < siz; i += k << 1)
                    {
                        for (int j = 0; j < k; ++j)
                        {
                            complex<double> z = data.w[j * l] * A[i + j + k];
                            A[i + j + k] = A[i + j] - z;
                            A[i + j] += z;
                        }
                    }
                }
                for (auto &i : A)
                {
                    i *= i;
                }
                for (int i = 0; i < (int)A.size(); ++i)
                {
                    B.push_back(A[-i & (siz - 1)] - conj(A[i]));
                }
                for (int i = 0; i < siz; ++i)
                {
                    if (i < (data.rev[i] >> (23 - len)))
                    {
                        std::swap(B[i], B[data.rev[i] >> (23 - len)]);
                    }
                }
                for (int k = 1; k < siz; k <<= 1)
                {
                    int l = (1 << 22) / k;
                    for (int i = 0; i < siz; i += k << 1)
                    {
                        for (int j = 0; j < k; ++j)
                        {
                            complex<double> z = data.w[j * l] * B[i + j + k];
                            B[i + j + k] = B[i + j] - z;
                            B[i + j] += z;
                        }
                    }
                }
                for (int i = 0; i < (int)B.size(); ++i)
                {
                    res.number.push_back(B[i].y / (siz << 2) + 0.5);
                }
                for (int i = 1; i < (int)res.size(); ++i)
                {
                    if (res.number[i - 1] >= base)
                    {
                        res.number[i] += res.number[i - 1] / base;
                        res.number[i - 1] %= base;
                    }
                }
                if (res.number.back() >= base)
                {
                    int up = res.number.back() / base;
                    res.number.back() %= base;
                    res.number.push_back(up);
                }
                res.shrink_to_fit();
            }
            return res;
        }
        bigint operator/(const bigint &__Val) const noexcept
        {
            // coming soon~~~
        }
        bigint operator/(const long long &__Val) const noexcept
        {
            assert(__Val);
            bigint res;
            long long v = __Val < 0 ? -__Val : __Val, Left = 0;
            res.mark = mark ^ (__Val < 0);
            res.number.assign(size(), 0);
            for (int i = res.size() - 1; i >= 0; --i)
            {
                Left = Left * base + number[i];
                res.number[i] = Left / v;
                Left %= v;
            }
            res.shrink_to_fit();
            return res;
        }
        bigint operator%(const long long &__Val) const noexcept
        {
            assert(__Val);
            long long Left = 0;
            for (int i = size() - 1; i >= 0; --i)
            {
                Left = Left * base + number[i];
                Left %= __Val;
            }
            return Left * (mark ? -1 : 1);
        }
        bigint operator<<(const int &__Val) const noexcept
        {
            bigint res;
            res.mark = mark;
            res.number.resize(size() + __Val);
            std::copy(number.begin(), number.end(), res.number.begin() + __Val);
            return res;
        }
        bigint operator>>(const int &__Val) const noexcept
        {
            if (__Val >= (int)size())
            {
                return 0;
            }
            bigint res;
            res.mark = mark;
            res.number.resize(size() - __Val);
            std::copy(number.begin() + __Val, number.end(), res.number.begin());
            return res;
        }
        bigint operator&(const int &__Val) const noexcept
        {
            bigint res = *this;
            res.number.resize(__Val);
            return res;
        }
        bigint operator|(const bigint &__Val) const noexcept
        {
            bigint res = __Val;
            res.mark |= mark;
            res.number.resize(size() + __Val.size());
            std::copy(number.begin(), number.end(), res.number.begin() + __Val.size());
            return res;
        }
        friend bigint abs(const bigint &__Val) noexcept
        {
            bigint res = __Val;
            res.mark = false;
            return res;
        }
        friend std::istream &operator>>(std::istream &ist, bigint &__Val) noexcept
        {
            __Val.clear();
            std::string tmp;
            ist >> tmp;
            __Val = tmp;
            return ist;
        }
        friend std::ostream &operator<<(std::ostream &ost, const bigint &__Val) noexcept
        {
            return ost << std::string(__Val);
        }
        operator std::string() const
        {
            if (empty())
            {
                return "0";
            }
            std::string res;
            if (mark)
            {
                res = "-";
            }
            if (base <= 36)
            {
                for (int i = size() - 1; i >= 0; --i)
                {
                    res += (char)(number[i] < 10 ? number[i] | 48 : 64 | (number[i] - 9));
                }
            }
            else if (pow(10, (int)log10(base)) == base)
            {
                res += std::to_string(number.back());
                for (int i = (int)size() - 2; i >= 0; --i)
                {
                    for (int j = base / 10; j > number[i]; j /= 10)
                    {
                        res += '0';
                    }
                    if (number[i])
                    {
                        res += std::to_string(number[i]);
                    }
                }
            }
            return res;
        }
        bigint &operator+=(const bigint &__Val) noexcept
        {
            return *this = *this + __Val;
        }
        bigint &operator-=(const bigint &__Val) noexcept
        {
            return *this = *this - __Val;
        }
        bigint &operator*=(const bigint &__Val) noexcept
        {
            return *this = *this * __Val;
        }
        bigint &operator/=(const bigint &__Val) noexcept
        {
            return *this = *this / __Val;
        }
        bigint &operator<<=(const int &__Val) noexcept
        {
            return *this = *this << __Val;
        }
        bigint &operator>>=(const int &__Val) noexcept
        {
            return *this = *this >> __Val;
        }
    };
    template <int base = 10>
    class bigfloat
    {
    private:
        std::vector<long long> number;
        bool mark;
        int point;
        int up_per_time;
        void shrink_to_fit() noexcept
        {
            while (!(number.empty() || number.back()))
            {
                number.pop_back();
            }
            if (number.empty())
            {
                mark = false;
                point = 0;
            }
        }

    public:
        class iterator
        {
        private:
            std::vector<long long>::iterator Iter;

        public:
            constexpr iterator() noexcept
            {
            }
            iterator(const std::vector<long long>::iterator &__Val) noexcept
            {
                Iter = __Val;
            }
            iterator operator++() noexcept
            {
                return ++Iter;
            }
            iterator operator++(int) noexcept
            {
                return Iter++;
            }
            iterator operator--() noexcept
            {
                return --Iter;
            }
            iterator operator--(int) noexcept
            {
                return Iter--;
            }
            bool operator==(const iterator &__Val) const noexcept
            {
                return Iter == __Val.Iter;
            }
            bool operator!=(const iterator &__Val) const noexcept
            {
                return Iter != __Val.Iter;
            }
            long long &operator*() const noexcept
            {
                return *Iter;
            }
        };
        class reverse_iterator
        {
        private:
            std::vector<long long>::reverse_iterator Iter;

        public:
            constexpr reverse_iterator() noexcept
            {
            }
            reverse_iterator(const std::vector<long long>::reverse_iterator &__Val) noexcept
            {
                Iter = __Val;
            }
            reverse_iterator operator++() noexcept
            {
                return ++Iter;
            }
            reverse_iterator operator++(int) noexcept
            {
                return Iter++;
            }
            reverse_iterator operator--() noexcept
            {
                return --Iter;
            }
            reverse_iterator operator--(int) noexcept
            {
                return Iter--;
            }
            bool operator==(const reverse_iterator &__Val) const noexcept
            {
                return Iter == __Val.Iter;
            }
            bool operator!=(const reverse_iterator &__Val) const noexcept
            {
                return Iter != __Val.Iter;
            }
            long long &operator*() const noexcept
            {
                return *Iter;
            }
        };
        iterator begin() noexcept
        {
            return number.begin();
        }
        iterator end() noexcept
        {
            return number.end();
        }
        reverse_iterator rbegin() noexcept
        {
            return number.rbegin();
        }
        reverse_iterator rend() noexcept
        {
            return number.rend();
        }
        constexpr bigfloat() noexcept
        {
            number.clear();
            mark = false;
            point = 0;
            up_per_time = 10;
        }
        bigfloat(const long double &__Val) noexcept
        {
            *this = std::to_string(__Val);
        }
        bigfloat(const std::string &__Val) noexcept
        {
            number.clear();
            mark = false;
            point = 0;
            up_per_time = 10;
            std::string tmp = __Val;
            std::reverse(tmp.begin(), tmp.end());
            if (tmp.back() == '-')
            {
                mark = true;
                tmp.pop_back();
            }
            if (base <= 36)
            {
                int i = 0;
                while (i < (int)tmp.length() && tmp[i] != '.')
                {
                    number.push_back(tmp[i] <= '9' ? tmp[i] & 15 : (tmp[i] & 31) + 9);
                    ++i;
                    --point;
                }
                if (i < (int)tmp.length())
                {
                    ++i;
                    while (i < (int)tmp.length())
                    {
                        number.push_back(tmp[i] <= '9' ? tmp[i] & 15 : (tmp[i] & 31) + 9);
                        ++i;
                    }
                }
                else
                {
                    point = 0;
                }
            }
            else if (pow(10, (int)log10(base)) == base)
            {
                int len = log10(base), v = 1, dot = tmp.find('.');
                if (dot == -1)
                {
                    point = 0;
                }
                else
                {
                    tmp.erase(dot, 1);
                    tmp = std::string((len - dot % len) % len, '0') + tmp;
                    point = -(dot / len + (dot % len != 0));
                }
                for (int i = 0; i < (int)tmp.length(); ++i)
                {
                    if (i % len == 0)
                    {
                        number.push_back((tmp[i] & 15) * (v = 1));
                    }
                    else
                    {
                        number.back() += (tmp[i] & 15) * (v *= 10);
                    }
                }
            }
            shrink_to_fit();
        }
        void clear() noexcept
        {
            number.clear();
            mark = false;
            point = 0;
            up_per_time = 10;
        }
        void reset_point(const int &__Val) noexcept
        {
            if (point < __Val)
            {
                *this >>= __Val - point;
            }
            if (point > __Val)
            {
                *this <<= point - __Val;
            }
            point = __Val;
        }
        void delete_left_zero() noexcept
        {
            int __Val = 0;
            while (__Val < (int)size() && !number[__Val])
            {
                ++__Val;
            }
            reset_point(__Val + point);
        }
        void reset_up_per_time(const int &__Val) noexcept
        {
            up_per_time = __Val;
        }
        bool empty() const noexcept
        {
            return !mark && number.empty() && !point;
        }
        bool operator<(const bigfloat &__Val) const noexcept
        {
            if (mark != __Val.mark)
            {
                return mark && !__Val.mark;
            }
            if (mark)
            {
                return -__Val < -*this;
            }
            if (empty() ^ __Val.empty())
            {
                return empty();
            }
            if (empty() && __Val.empty())
            {
                return false;
            }
            if (size() + point != __Val.size() + __Val.point)
            {
                return (int)size() + point < (int)__Val.size() + __Val.point;
            }
            for (int i = size() - 1, j = __Val.size() - 1; i >= 0 && j >= 0; --i, --j)
            {
                if (number[i] != __Val.number[j])
                {
                    return number[i] < __Val.number[j];
                }
            }
            if (size() != __Val.size())
            {
                return size() < __Val.size();
            }
            return false;
        }
        bool operator==(const bigfloat &__Val) const noexcept
        {
            return mark == __Val.mark && point == __Val.point && number == __Val.number;
        }
        bool operator>(const bigfloat &__Val) const noexcept
        {
            return __Val < *this;
        }
        bool operator<=(const bigfloat &__Val) const noexcept
        {
            return *this == __Val || *this < __Val;
        }
        bool operator>=(const bigfloat &__Val) const noexcept
        {
            return *this == __Val || *this > __Val;
        }
        bool operator!=(const bigfloat &__Val) const noexcept
        {
            return !(*this == __Val);
        }
        size_t size() const noexcept
        {
            return number.size();
        }
        bigfloat operator+() const noexcept
        {
            return *this;
        }
        bigfloat operator-() const noexcept
        {
            if (empty())
            {
                return *this;
            }
            bigfloat res = *this;
            res.mark ^= true;
            return res;
        }
        bigfloat operator+(const bigfloat &__Val) const noexcept
        {
            if (empty())
            {
                return __Val;
            }
            if (__Val.empty())
            {
                return *this;
            }
            if (mark)
            {
                return __Val - (-*this);
            }
            if (__Val.mark)
            {
                return *this - (-__Val);
            }
            bigfloat res;
            res.number.assign(std::max(size() + point, __Val.size() - __Val.point) - std::min(point, __Val.point), 0);
            res.point = std::min(point, __Val.point);
            for (int i = 0; i < (int)size(); ++i)
            {
                res.number[i + point - res.point] += number[i];
            }
            for (int i = 0; i < (int)__Val.size(); ++i)
            {
                res.number[i + __Val.point - res.point] += __Val.number[i];
            }
            for (int i = 1; i < (int)res.size(); ++i)
            {
                if (res.number[i - 1] >= base)
                {
                    res.number[i - 1] -= base;
                    ++res.number[i];
                }
            }
            if (res.number.back() >= base)
            {
                res.number.back() -= base;
                res.number.push_back(1);
            }
            res.shrink_to_fit();
            return res;
        }
        bigfloat operator-(const bigfloat &__Val) const noexcept
        {
            if (empty())
            {
                return -__Val;
            }
            if (__Val.empty())
            {
                return *this;
            }
            if (mark)
            {
                return -(-*this + __Val);
            }
            if (__Val.mark)
            {
                return *this + __Val;
            }
            if (*this < __Val)
            {
                return -(__Val - *this);
            }
            bigfloat res = *this;
            if (__Val.point < point)
            {
                res.reset_point(__Val.point);
            }
            for (int i = 0; i < (int)__Val.size(); ++i)
            {
                if (res.number[i] < __Val.number[i])
                {
                    res.number[i] += base;
                    --res.number[i + 1];
                }
                res.number[i] -= __Val.number[i];
            }
            for (int i = __Val.size(); res.number[i] < 0; ++i)
            {
                res.number[i] += base;
                --res.number[i + 1];
            }
            res.shrink_to_fit();
            return res;
        }
        bigfloat operator*(const bigfloat &__Val) const noexcept
        {
            if (empty() || __Val.empty())
            {
                return 0;
            }
            bigfloat res;
            if (size() + __Val.size() <= 512)
            {
                res.mark = mark ^ __Val.mark;
                res.point = point + __Val.point;
                res.number.assign(size() + __Val.size(), 0);
                for (int i = 0; i < (int)size(); ++i)
                {
                    for (int j = 0; j < (int)__Val.size(); ++j)
                    {
                        res.number[i + j] += number[i] * __Val.number[j];
                    }
                }
                for (int i = 1; i < (int)res.size(); ++i)
                {
                    if (res.number[i - 1] >= base)
                    {
                        res.number[i] += res.number[i - 1] / base;
                        res.number[i - 1] %= base;
                    }
                }
                res.shrink_to_fit();
            }
            else if (size() + __Val.size() <= 40000000)
            {
                res.mark = mark ^ __Val.mark;
                res.point = point + __Val.point;
                if (!data.init_for_FFT)
                {
                    data.init();
                }
                int len = 32 - __builtin_clz(size() + __Val.size()), siz = 1 << len;
                std::vector<complex<double>> A(siz, 0), B;
                for (int i = 0; i < (int)size(); ++i)
                {
                    A[i].x = number[i];
                }
                for (int i = 0; i < (int)__Val.size(); ++i)
                {
                    A[i].y = __Val.number[i];
                }
                for (int i = 0; i < siz; ++i)
                {
                    if (i < (data.rev[i] >> (23 - len)))
                    {
                        std::swap(A[i], A[data.rev[i] >> (23 - len)]);
                    }
                }
                for (int k = 1; k < siz; k <<= 1)
                {
                    int l = (1 << 22) / k;
                    for (int i = 0; i < siz; i += k << 1)
                    {
                        for (int j = 0; j < k; ++j)
                        {
                            complex<double> z = data.w[j * l] * A[i + j + k];
                            A[i + j + k] = A[i + j] - z;
                            A[i + j] += z;
                        }
                    }
                }
                for (auto &i : A)
                {
                    i *= i;
                }
                for (int i = 0; i < (int)A.size(); ++i)
                {
                    B.push_back(A[-i & (siz - 1)] - conj(A[i]));
                }
                for (int i = 0; i < siz; ++i)
                {
                    if (i < (data.rev[i] >> (23 - len)))
                    {
                        std::swap(B[i], B[data.rev[i] >> (23 - len)]);
                    }
                }
                for (int k = 1; k < siz; k <<= 1)
                {
                    int l = (1 << 22) / k;
                    for (int i = 0; i < siz; i += k << 1)
                    {
                        for (int j = 0; j < k; ++j)
                        {
                            complex<double> z = data.w[j * l] * B[i + j + k];
                            B[i + j + k] = B[i + j] - z;
                            B[i + j] += z;
                        }
                    }
                }
                for (int i = 0; i < (int)B.size(); ++i)
                {
                    res.number.push_back(B[i].y / (siz << 2) + 0.5);
                }
                for (int i = 1; i < (int)res.size(); ++i)
                {
                    if (res.number[i - 1] >= base)
                    {
                        res.number[i] += res.number[i - 1] / base;
                        res.number[i - 1] %= base;
                    }
                }
                if (res.number.back() >= base)
                {
                    int up = res.number.back() / base;
                    res.number.back() %= base;
                    res.number.push_back(up);
                }
                res.shrink_to_fit();
            }
            return res;
        }
        bigfloat operator/(const bigfloat &__Val) const noexcept
        {
            // coming soon~~~
        }
        bigfloat operator/(const long long &__Val) const noexcept
        {
            assert(__Val);
            bigfloat res;
            long long v = __Val < 0 ? -__Val : __Val, Left = 0;
            res.mark = mark ^ (__Val < 0);
            res.number.assign(size() + up_per_time, 0);
            for (int i = size() - 1; i >= 0; --i)
            {
                Left = Left * base + number[i];
                res.number[i + up_per_time] = Left / v;
                Left %= v;
            }
            res.shrink_to_fit();
            return res;
        }
        bigfloat operator<<(const int &__Val) const noexcept
        {
            bigfloat res;
            res.mark = mark;
            res.point = point;
            res.number.resize(size() + __Val);
            std::copy(number.begin(), number.end(), res.number.begin() + __Val);
            return res;
        }
        bigfloat operator>>(const int &__Val) const noexcept
        {
            if (__Val >= (int)size())
            {
                return 0;
            }
            bigfloat res;
            res.mark = mark;
            res.point = point;
            res.number.resize(size() - __Val);
            std::copy(number.begin() + __Val, number.end(), res.number.begin());
            return res;
        }
        friend bigfloat abs(const bigfloat &__Val) noexcept
        {
            bigfloat res = __Val;
            res.mark = false;
            return res;
        }
        friend std::istream &operator>>(std::istream &ist, bigfloat &__Val) noexcept
        {
            __Val.clear();
            std::string tmp;
            ist >> tmp;
            __Val = tmp;
            return ist;
        }
        friend std::ostream &operator<<(std::ostream &ost, const bigfloat &__Val)
        {
            return ost << std::string(__Val);
        }
        operator std::string() const
        {
            std::string res;
            if (empty())
            {
                return "0";
            }
            if (mark)
            {
                res = "-";
            }
            bool dot = false;
            if (base <= 36)
            {
                if ((int)size() + point <= 0)
                {
                    res += "0.";
                    dot = true;
                    for (int i = 0; i > (int)size() + point; --i)
                    {
                        res += '0';
                    }
                }
                for (int i = size() - 1; i >= 0; --i)
                {
                    res += (char)(number[i] < 10 ? number[i] | 48 : 64 | (number[i] - 9));
                    if (!(i + point) && i)
                    {
                        res += '.';
                        dot = true;
                    }
                }
                for (int i = point; i > 0; --i)
                {
                    res += '0';
                }
            }
            else if (pow(10, (int)log10(base)) == base)
            {
                if ((int)size() + point <= 0)
                {
                    res += "0.";
                    dot = true;
                    for (int i = 0; i > (int)size() + point; --i)
                    {
                        for (int j = base / 10; j > 0; j /= 10)
                        {
                            res += '0';
                        }
                    }
                }
                if (dot)
                {
                    for (int i = base / 10; i > number.back(); i /= base)
                    {
                        res += '0';
                    }
                }
                res += std::to_string(number.back());
                for (int i = (int)size() - 2; i >= 0; --i)
                {
                    if (i + point == -1)
                    {
                        res += '.';
                        dot = true;
                    }
                    for (int j = base / 10; j > number[i]; j /= 10)
                    {
                        res += '0';
                    }
                    if (number[i])
                    {
                        res += std::to_string(number[i]);
                    }
                }
            }
            while (dot && res.back() == '0')
            {
                res.pop_back();
            }
            if (res.back() == '.')
            {
                res.pop_back();
            }
            return res;
        }
        bigfloat &operator+=(const bigfloat &__Val) noexcept
        {
            return *this = *this + __Val;
        }
        bigfloat &operator-=(const bigfloat &__Val) noexcept
        {
            return *this = *this - __Val;
        }
        bigfloat &operator*=(const bigfloat &__Val) noexcept
        {
            return *this = *this * __Val;
        }
        bigfloat &operator/=(const bigfloat &__Val) noexcept
        {
            return *this = *this / __Val;
        }
        bigfloat &operator<<=(const int &__Val) noexcept
        {
            return *this = *this << __Val;
        }
        bigfloat &operator>>=(const int &__Val) noexcept
        {
            return *this = *this >> __Val;
        }
    };
} // namespace zjcSTL
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string ans[100005];
queue<int> que;
int n;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    que.push(1 % n);
    ans[1 % n] = "1";
    while (ans[0].empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < 2; ++i)
        {
            if (ans[(((now << 3) + (now << 1)) | i) % n].empty())
            {
                ans[(((now << 3) + (now << 1)) | i) % n] = ans[now] + (char)('0' | i);
                que.push((((now << 3) + (now << 1)) | i) % n);
            }
        }
    }
    cout << zjcSTL::bigint<10>(ans[0]) / n << ' ' << ans[0] << endl;
    return 0;
}