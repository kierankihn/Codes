#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = std::getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = std::getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}  // namespace input
namespace output
{
    void write()
    {
        std::putchar('\n');
    }
    void write(char ch)
    {
        std::putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            std::putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        std::putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        std::putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        std::putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        std::putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}  // namespace output
namespace matrix
{
    typedef __int128 LL;
    struct Matrix
    {
        static const int MAXSIZE = 10;
        int colume, line;
        LL m[MAXSIZE][MAXSIZE];
        Matrix(int col = 0, int ln = 0)
            : colume(col), line(ln)
        {
            memset(m, 0, sizeof(m));
        }
        Matrix &operator=(Matrix a)
        {
            this->colume = a.colume, this->line = a.line;
            for (int i = 1; i <= a.line; i++)
            {
                for (int j = 1; j <= a.colume; j++)
                {
                    this->m[i][j] = a.m[i][j];
                }
            }
            return *this;
        }
    };
    Matrix operator+(const Matrix a, const Matrix b)
    {
        if (a.colume != b.colume)
        {
            throw "Matrix Colume Not equal";
        }
        if (a.line != b.line)
        {
            throw "Matrix line Not equal";
        }
        Matrix res(a.colume, a.line);
        for (int i = 1; i <= a.line; i++)
        {
            for (int j = 1; j <= a.colume; i++)
            {
                res.m[i][j] = a.m[i][j] + b.m[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix a, const Matrix b)
    {
        if (a.colume != b.colume)
        {
            throw "Matrix Colume Not equal";
        }
        if (a.line != b.line)
        {
            throw "Matrix line Not equal";
        }
        Matrix res(a.colume, a.line);
        for (int i = 1; i <= a.line; i++)
        {
            for (int j = 1; j <= a.colume; i++)
            {
                res.m[i][j] = a.m[i][j] - b.m[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const Matrix a, const Matrix b)
    {
        if (a.colume != b.line)
        {
            output::write(a.colume, b.line);
            throw "Matrix cannot multiple";
        }
        Matrix res(a.colume, b.line);
        for (int i = 1; i <= a.line; i++)
        {
            for (int j = 1; j <= b.colume; j++)
            {
                for (int k = 1; k <= a.colume; k++)
                {
                    res.m[i][j] += a.m[i][k] * b.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator%(const Matrix a, const int b)
    {
        Matrix res(a.colume, a.line);
        for (int i = 1; i <= a.line; i++)
        {
            for (int j = 1; j <= a.colume; j++)
            {
                res.m[i][j] = a.m[i][j] % b;
            }
        }
        return res;
    }
    Matrix getUnitMatrix(int x)
    {
        Matrix res(x, x);
        for (int i = 1; i <= x; i++)
        {
            res.m[i][i] = 1;
        }
        return res;
    }
    Matrix qpow(Matrix a, LL b, LL mod)
    {
        bool flag = true;
        Matrix res;
        while (b)
        {
            if (b & 1)
            {
                if (flag)
                {
                    res  = a;
                    flag = false;
                }
                else
                {
                    res = res * a;
                    res = res % mod;
                }
            }
            a = a * a;
            a = a % mod;
            b >>= 1;
        }
        return res;
    }
}  // namespace matrix
namespace solution
{
    typedef __int128 LL;
    const LL MOD = 998244353;

    std::string s;

    LL n;
    matrix::Matrix m0(3, 1);
    matrix::Matrix zy(3, 3);

    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c, b = b >> 1;
        }
        return res;
    }

    void init()
    {
        m0.m[1][1] = 1, m0.m[1][2] = 0;
        zy.m[1][1] = 1, zy.m[1][2] = n, zy.m[2][1] = 0, zy.m[2][2] = qpow(10, s.size(), MOD);
    }
    int main()
    {
        using input::read;
        using output::write;

        matrix::Matrix res(2, 1);

        std::cin >> s;
        n = std::stoll(s);

        init();

        zy = zy % MOD;

        res = matrix::qpow(zy, n, MOD);
        res = m0 * res;
        res = res % MOD;

        write(res.m[1][2]);
        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}