#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int t;
    LL n, a, b;
    struct Node
    {
        LL x, y;
        Node() {}
        Node(LL x_, LL y_) : x(x_), y(y_) {}
    };
    Node solve(LL id, LL pos)
    {
        if (id == 0)
        {
            return Node(0, 0);
        }
        LL cnt = 1LL << (2 * (id - 1));
        LL len = 1LL << (id - 1);
        Node res = solve(id - 1, pos % cnt);
        if (pos / cnt == 0)
        {
            res = Node(res.y, res.x);
        }
        if (pos / cnt == 1)
        {
            res = Node(res.x, res.y + len);
        }
        if (pos / cnt == 2)
        {
            res = Node(res.x + len, res.y + len);
        }
        if (pos / cnt == 3)
        {
            res = Node(2LL * len - res.y - 1, len - res.x - 1);
        }
        return res;
    }
    int main()
    {
        std::cin >> t;
        while (t--)
        {
            std::cin >> n >> a >> b;
            Node posa = solve(n, a - 1), posb = solve(n, b - 1);
            std::cout << posa.x << " " << posa.y << " " << posb.x << " " << posb.y << std::endl;
            std::cout << (LL)std::round(10LL * std::sqrt((posa.x - posb.x) * (posa.x - posb.x) + (posa.y - posb.y) * (posa.y - posb.y))) << std::endl;
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}