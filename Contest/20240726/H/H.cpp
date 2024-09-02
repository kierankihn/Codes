/**
 * @author Kieran Kihn
 * @date 2024.07.26
 * @name H
 * @link
 */
#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    i64 al, ar, bl, br;

    std::vector<i64> va, vb;
    void init(i64 al, i64 ar, i64 bl, i64 br)
    {
        for (i64 i = 2; i * i <= al; i++)
        {
            while (al % i == 0)
            {
                va.push_back(i), al /= i;
            }
        }
        if (al != 1)
        {
            va.push_back(al);
        }
        for (i64 i = 2; i * i <= ar; i++)
        {
            while (ar % i == 0)
            {
                va.push_back(i), ar /= i;
            }
        }
        if (ar != 1)
        {
            va.push_back(ar);
        }
        for (i64 i = 2; i * i <= bl; i++)
        {
            while (bl % i == 0)
            {
                vb.push_back(i), bl /= i;
            }
        }
        if (bl != 1)
        {
            vb.push_back(bl);
        }
        for (i64 i = 2; i * i <= br; i++)
        {
            while (br % i == 0)
            {
                vb.push_back(i), br /= i;
            }
        }
        if (br != 1)
        {
            vb.push_back(br);
        }
    }

    bool check()
    {
        std::sort(va.begin(), va.end());
        std::sort(vb.begin(), vb.end());

        int i = 0, j = 0;
        while ((i != va.size()) && (va[i] == 2 || va[i] == 3))
        {
            i++;
        }
        while ((j != vb.size()) && (vb[j] == 2 || vb[j] == 3))
        {
            j++;
        }
        for (; i != va.size() && j != vb.size(); i++, j++)
        {
            if (va[i] != vb[j])
            {
                return false;
            }
        }
        if (i != va.size() || j != vb.size())
        {
            return false;
        }

        return true;
    }
    int solve()
    {
        init(al, ar, bl, br);

        i64 res = 0;
        if (check() == false)
        {
            write(-1);
            exit(0);
        }

        int a2 = 0, a3 = 0, b2 = 0, b3 = 0;
        for (auto i : va)
        {
            if (i == 2)
            {
                a2++;
            }
            if (i == 3)
            {
                a3++;
            }
        }
        for (auto i : vb)
        {
            if (i == 2)
            {
                b2++;
            }
            if (i == 3)
            {
                b3++;
            }
        }

        res += std::abs(a3 - b3);
        if (a3 <= b3)
        {
            for (int i = 1; i <= b3 - a3; i++)
            {
                if (bl % 3 == 0)
                {
                    bl /= 3, bl *= 2;
                }
                else
                {
                    br /= 3, br *= 2;
                }
            }
            b2 += std::abs(a3 - b3);
        }
        else
        {
            for (int i = 1; i <= a3 - b3; i++)
            {
                if (al % 3 == 0)
                {
                    al /= 3, al *= 2;
                }
                else
                {
                    ar /= 3, ar *= 2;
                }
            }
            a2 += std::abs(a3 - b3);
        }

        if (a2 <= b2)
        {
            for (int i = 1; i <= b2 - a2; i++)
            {
                if (bl % 2 == 0)
                {
                    bl /= 2;
                }
                else
                {
                    br /= 2;
                }
            }
        }
        else
        {
            for (int i = 1; i <= a2 - b2; i++)
            {
                if (al % 2 == 0)
                {
                    al /= 2;
                }
                else
                {
                    ar /= 2;
                }
            }

            
        }

        return res += std::abs(a2 - b2);
    }

    int main()
    {
        read(al, ar, bl, br);

        write(solve());

        write(al, ar), write(bl, br);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}