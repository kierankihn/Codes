#include <bits/stdc++.h>
using namespace std;
inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-'), x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}

struct Time
{
    int t;
    int k;
    Time(int t_, int k_) : t(t_), k(k_)
    {
    }
    bool operator<(Time a)
    {
        if (t == a.t)
        {
            return k < a.k;
        }
        return t < a.t;
    }
};
int n;
int ans_now, ans;
vector<Time> a;
int main()
{
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        l = readInt();
        r = readInt();
        a.push_back(Time(l, 1));
        a.push_back(Time(r + 1, -1));
    }
    sort(a.begin(), a.end());
    for (unsigned int i = 0; i < a.size(); i++)
    {
        ans_now += a[i].k;
        ans = max(ans, ans_now);
    }
    write(ans);
    putchar('\n');
    return 0;
}
