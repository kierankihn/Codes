#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXSIZE = 3;
    const int MOD = 1e4;
    class Matrix
    {
    private:
        LL length, width;
        LL m[MAXSIZE][MAXSIZE];

    public:
        Matrix(LL, LL);
        void indentify(LL);
        void resize(LL, LL);
        LL *operator[](int);
        friend Matrix operator+(Matrix, Matrix);
        friend Matrix operator*(Matrix, Matrix);
        friend Matrix operator%(Matrix, LL);
        friend Matrix qpow(Matrix, LL, LL);
    };
    Matrix::Matrix(LL _length = 0, LL _width = 0) : length(_length), width(_width)
    {
        std::memset(m, 0, sizeof(m));
    }
    LL *Matrix::operator[](int x)
    {
        return m[x];
    }
    void Matrix::resize(LL _length, LL _width)
    {
        length = _length, width = _width;
    }
    void Matrix::indentify(LL x)
    {
        resize(x, x);
        std::memset(m, 0, sizeof(m));
        for (int i = 1; i <= x; i++)
        {
            m[i][i] = 1;
        }
    }
    Matrix operator+(Matrix a, Matrix b)
    {
        if (a.length != b.length || a.width != b.width)
        {
            throw;
        }
        Matrix res(a.length, a.width);
        for (int i = 1; i <= res.length; i++)
        {
            for (int j = 1; j <= res.width; j++)
            {
                res[i][j] = a[i][j] + b[i][j];
            }
        }
        return res;
    }
    Matrix operator*(Matrix a, Matrix b)
    {
        if (a.width != b.length)
        {
            throw;
        }
        Matrix res(a.length, b.width);
        for (int i = 1; i <= res.length; i++)
        {
            for (int j = 1; j <= res.width; j++)
            {
                for (int k = 1; k <= a.width; k++)
                {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator%(Matrix a, LL b)
    {
        Matrix res(a.length, a.width);
        for (int i = 1; i <= res.length; i++)
        {
            for (int j = 1; j <= res.width; j++)
            {
                res[i][j] = a[i][j] % b;
            }
        }
        return res;
    }
    Matrix qpow(Matrix a, LL b, LL c)
    {
        if (a.length != a.width)
        {
            throw;
        }
        Matrix res(a.length, a.width);
        res.indentify(a.length);
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            a = a * a % c;
            b = b >> 1;
        }
        return res;
    }
    int main()
    {
        LL n;
        while (scanf("%lld", &n) && n != -1)
        {
            Matrix ans(1, 2), p(2, 2);
            ans[1][1] = 1, ans[1][2] = 0;
            p[1][1] = 1, p[1][2] = 1, p[2][1] = 1, p[2][2] = 0;
            ans = ans * qpow(p, n, MOD) % MOD;
            printf("%lld\n", ans[1][2]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}