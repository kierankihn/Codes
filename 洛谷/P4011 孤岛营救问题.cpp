#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 10 + 5;
    const int MAX2P = (1 << 10) + 5;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    int n, m, p, k, s;
    std::vector<int> key[MAXN][MAXN];
    int dist[MAXN][MAXN][MAX2P];
    int mp[MAXN][MAXN][MAXN][MAXN];
    int getKey(int x, int y, int now)
    {
        for (auto &i : key[x][y])
        {
            now = now | (1 << (i - 1));
        }
        return now;
    }
    bool checkKey(int x, int y, int nx, int ny, int now)
    {
        if (mp[x][y][nx][ny] == -1)
        {
            return true;
        }
        if (mp[x][y][nx][ny] == 0)
        {
            return false;
        }
        return (now & (1 << (mp[x][y][nx][ny] - 1)));
    }
    int bfs()
    {
        std::memset(dist, -1, sizeof(dist));
        std::queue<std::pair<std::pair<int, int>, int>> q;
        q.push(std::make_pair(std::make_pair(1, 1), getKey(1, 1, 0))), dist[1][1][getKey(1, 1, 0)] = 0;
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            int x = u.first.first, y = u.first.second, now = u.second;
            if (x == n && y == m)
            {
                return dist[x][y][now];
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
                {
                    if (checkKey(x, y, nx, ny, now))
                    {
                        if (dist[nx][ny][getKey(nx, ny, now)] == -1)
                        {
                            dist[nx][ny][getKey(nx, ny, now)] = dist[x][y][now] + 1;
                            q.push(std::make_pair(std::make_pair(nx, ny), getKey(nx, ny, now)));
                        }
                    }
                }
            }
        }
        return -1;
    }
    int main()
    {
        std::memset(mp, -1, sizeof(mp));
        scanf("%d%d%d", &n, &m, &p);
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            int x, y, nx, ny, dis;
            scanf("%d%d%d%d%d", &x, &y, &nx, &ny, &dis);
            mp[x][y][nx][ny] = mp[nx][ny][x][y] = dis;
        }
        scanf("%d", &s);
        for (int i = 1; i <= s; i++)
        {
            int x, y, q;
            scanf("%d%d%d", &x, &y, &q);
            key[x][y].push_back(q);
        }
        printf("%d\n", bfs());
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}