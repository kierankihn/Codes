#include <bits/stdc++.h>
namespace matrix
{
    const int MAXN = 30 + 5;
    typedef long long LL;
    class Matrix
    {
    private:

    public:
        LL n;
        LL m[MAXN][MAXN];
        Matrix(LL);
        void resize(int);
        LL *operator[](int);
        friend Matrix operator+(const Matrix, const Matrix);
        friend Matrix operator*(const Matrix, const Matrix);
        friend Matrix operator%(const Matrix, const LL);
        friend Matrix solve(Matrix, LL, LL);
        friend Matrix qpow(Matrix, LL, LL);
    };
    Matrix::Matrix(LL _n = 0) : n(_n)
    {
        std::memset(m, 0, sizeof(m));
        for (int i = 1; i <= n; i++)
        {
            m[i][i] = 1;
        }
    }
    LL *Matrix::operator[](int x)
    {
        return m[x];
    }
    void Matrix::resize(int _n)
    {
        n = _n;
    }
    Matrix operator+(const Matrix a, const Matrix b)
    {
        if (a.n != b.n)
        {
            throw "Error: the two adding Matrix's size do not equal.";
        }
        Matrix res;
        res.resize(a.n);
        for (int i = 1; i <= res.n; i++)
        {
            for (int j = 1; j <= res.n; j++)
            {
                res[i][j] = a.m[i][j] + b.m[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const Matrix a, const Matrix b)
    {
        if (a.n != b.n)
        {
            throw "Error: the two mulipling Matrix's size do not equal.";
        }
        Matrix res;
        res.resize(a.n);
        for (int i = 1; i <= res.n; i++)
        {
            for (int j = 1; j <= res.n; j++)
            {
                res[i][j] = 0;
                for (int k = 1; k <= res.n; k++)
                {
                    res[i][j] += a.m[i][k] * b.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator%(const Matrix a, const LL x)
    {
        Matrix res;
        res.resize(a.n);
        for (int i = 1; i <= a.n; i++)
        {
            for (int j = 1; j <= a.n; j++)
            {
                res[i][j] = a.m[i][j] % x;
            }
        }
        return res;
    }
    Matrix qpow(Matrix a, LL b, LL m)
    {
        Matrix res(a.n);
        while (b)
        {
            if (b & 1)
            {
                res = res * a % m;
            }
            b = b >> 1;
            a = a * a % m;
        }
        return res;
    }
    Matrix solve(Matrix x, LL k, LL m)
    {
        if (k == 1)
        {
            return x;
        }
        Matrix res(x.n);
        res = res + qpow(x, k >> 1, m) % m;
        res = res * solve(x, k >> 1, m) % m;
        if (k & 1)
        {
            res = res + qpow(x, k, m) % m;
        }
        return res % m;
    }
};
namespace solution
{
    typedef long long LL;
    const int MAXN = 30 + 5;
    using matrix::Matrix;
    LL n, m, k;
    Matrix ans;
    int main()
    {
        scanf("%lld%lld%lld", &n, &k, &m);
        ans.resize(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lld", &ans[i][j]);
            }
        }
        ans = ans % m;
        ans = matrix::solve(ans, k, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%lld%c", ans[i][j], j == n ? '\n' : ' ');
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}