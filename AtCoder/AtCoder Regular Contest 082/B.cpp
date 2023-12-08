#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int DELTA = 16000;
    const int MAXN = 32000 + 5;
    int x, y;
    std::string a;
    int prepos = 0, cnt = 0;
    std::bitset<MAXN> dpx, dpy;
    int main()
    {
        std::cin >> a >> x >> y;
        a += 'T', x += DELTA, y += DELTA, dpx[DELTA] = dpy[DELTA] = 1;
        for (std::size_t i = 0; i < a.length(); i++)
        {
            if (a[i] == 'T')
            {
                if (cnt == 0)
                {
                    x -= i;
                }
                else
                {
                    int len = i - prepos - 1;
                    if (len != 0)
                    {
                        if (cnt & 1)
                        {
                            dpy = (dpy << len) | (dpy >> len);
                        }
                        else
                        {
                            dpx = (dpx << len) | (dpx >> len);
                        }
                    }
                }
                prepos = i, cnt++;
            }
        }
        if (dpx[x] && dpy[y])
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}