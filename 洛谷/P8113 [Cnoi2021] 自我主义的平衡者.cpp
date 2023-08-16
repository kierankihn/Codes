#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    using input::read;
    using output::write;
    int n;
    int m;
    int a[MAXN];
    LL sum;
    double avr;
    int main()
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (avr <= a[i])
            {
                sum += m;
            }
            avr = (double)sum / i;
        }
        std::cout << avr << " ";
        sum = 0;
        for (int i = n; i >= 1; i--)
        {
            if (avr <= a[i])
            {
                sum += m;
            }
            avr = (double)sum / (n - i + 1);
        }
        std::cout << avr << std::endl;
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}