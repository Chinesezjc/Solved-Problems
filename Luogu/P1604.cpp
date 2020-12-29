// This Code was made by Chinese_zjc_.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace zjcSTL
{
    template <size_t base = 10>
    class bigint
    {
    private:
        std::vector<long long> number;
        bool mark;
        void shrink_to_fit()
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
        constexpr bigint()
        {
            number.clear();
            mark = false;
        }
        bigint(const long long &__Val)
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
        void clear()
        {
            number.clear();
            mark = false;
        }
        bool empty() const
        {
            return !mark && number.empty();
        }
        bool operator<(const bigint<base> &__Val) const
        {
            if (mark != __Val.mark)
            {
                return mark && !__Val.mark;
            }
            if (mark)
            {
                return -__Val < -*this;
            }
            if (size() != __Val.size())
            {
                return size() < __Val.size();
            }
            if (size() == 0)
            {
                return false;
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
        bool operator==(const bigint<base> &__Val) const
        {
            return base == __Val.base && mark == __Val.mark && number == __Val.number;
        }
        bool operator>(const bigint<base> &__Val) const
        {
            return __Val < *this;
        }
        bool operator<=(const bigint<base> &__Val) const
        {
            return *this == __Val || *this < __Val;
        }
        bool operator>=(const bigint<base> &__Val) const
        {
            return *this == __Val || __Val < *this;
        }
        bool operator!=(const bigint<base> &__Val) const
        {
            return !(*this == __Val);
        }
        size_t size() const
        {
            return number.size();
        }
        bigint<base> operator-() const
        {
            bigint<base> res = *this;
            res.mark ^= true;
            return res;
        }
        bigint<base> operator+(const bigint<base> &__Val) const
        {
            if (mark)
            {
                return __Val - (-*this);
            }
            if (__Val.mark)
            {
                return *this - (-__Val);
            }
            bigint<base> res;
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
        bigint<base> operator-(const bigint<base> &__Val) const
        {
            if (mark)
            {
                return -(*this + __Val);
            }
            if (__Val.mark)
            {
                return *this + __Val;
            }
            if (*this < __Val)
            {
                return -(__Val - *this);
            }
            bigint<base> res = *this;
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
        bigint<base> operator*(const bigint<base> &__Val) const
        {
            bigint<base> res;
            res.mark = mark ^ __Val.mark;
            if (size() + __Val.size() <= 4000)
            {
                res.number.assign(size() + __Val.size(), 0);
                for (int i = 0; i < (int)size(); ++i)
                {
                    for (int j = 0; j < (int)__Val.size(); ++j)
                    {
                        res.number[i + j] += number[i] * __Val.number[j];
                    }
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
            return res;
        }
        friend std::istream &operator>>(std::istream &ist, bigint<base> &__Val)
        {
            __Val.clear();
            std::string tmp;
            ist >> tmp;
            std::reverse(tmp.begin(), tmp.end());
            if (tmp.back() == '-')
            {
                __Val.mark = true;
                tmp.pop_back();
            }
            for (int i = 0; i < (int)tmp.length(); ++i)
            {
                __Val.number.push_back(tmp[i] <= '9' ? tmp[i] & 15 : (tmp[i] & 31) + 9);
            }
            __Val.shrink_to_fit();
            return ist;
        }
        friend std::ostream &operator<<(std::ostream &ost, const bigint<base> &__Val)
        {
            if (__Val.empty())
            {
                return ost << "0";
            }
            if (__Val.mark)
            {
                ost << '-';
            }
            if (base <= 36)
            {
                for (auto i = __Val.number.rbegin(); i != __Val.number.rend(); ++i)
                {
                    ost << (char)(*i < 10 ? *i | 48 : 64 | (*i - 9));
                }
            }
            return ost;
        }
    };
} // namespace zjcSTL

int n;
using namespace std;
using namespace zjcSTL;
int main()
{
    cin >> n;
    if (n == 2)
    {
        bigint<2> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 3)
    {
        bigint<3> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 4)
    {
        bigint<4> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 5)
    {
        bigint<5> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 6)
    {
        bigint<6> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 7)
    {
        bigint<7> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 8)
    {
        bigint<8> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 9)
    {
        bigint<9> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 10)
    {
        bigint<10> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 11)
    {
        bigint<11> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 12)
    {
        bigint<12> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 13)
    {
        bigint<13> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 14)
    {
        bigint<14> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 15)
    {
        bigint<15> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 16)
    {
        bigint<16> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 17)
    {
        bigint<17> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 18)
    {
        bigint<18> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 19)
    {
        bigint<19> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 20)
    {
        bigint<20> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 21)
    {
        bigint<21> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 22)
    {
        bigint<22> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 23)
    {
        bigint<23> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 24)
    {
        bigint<24> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 25)
    {
        bigint<25> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 26)
    {
        bigint<26> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 27)
    {
        bigint<27> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 28)
    {
        bigint<28> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 29)
    {
        bigint<29> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 30)
    {
        bigint<30> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 31)
    {
        bigint<31> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 32)
    {
        bigint<32> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 33)
    {
        bigint<33> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 34)
    {
        bigint<34> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 35)
    {
        bigint<35> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    if (n == 36)
    {
        bigint<36> a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}