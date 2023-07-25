#include <iostream>
#include <cmath>
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
    const double eps = 1e-7;
    const int MAXN = 100 + 5;
    int n;
    double val[MAXN][MAXN];
    int main()
    {
        using input::read;
        using output::write;
        read(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int tmp;
                read(tmp);
                val[i][j] = tmp;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int maxpos = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (fabs(val[j][i]) > fabs(val[maxpos][i]))
                {
                    maxpos = j;
                }
            }
            for (int j = 1; j <= n + 1; j++)
            {
                std::swap(val[i][j], val[maxpos][j]);
            }
            if (fabs(val[i][i]) <= eps)
            {
                puts("No Solution");
                return 0;
            }
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    double tmp = val[j][i] / val[i][i];
                    for (int k = i + 1; k <= n + 1; k++)
                    {
                        val[j][k] -= val[i][k] * tmp;
                    }
                }
            }
        }
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        for (int i = 1; i <= n; i++)
        {
            std::cout << val[i][n + 1] / val[i][i] << std::endl;
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}