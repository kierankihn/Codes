#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    int n;
    struct IP
    {
        int id;
        int a, b, c, d, e;
        IP(int _id, int _a = 0, int _b = 0, int _c = 0, int _d = 0, int _e = 0) : id(_id), a(_a), b(_b), c(_c), d(_d), e(_e) {}
    };
    bool operator<(const IP a, const IP b)
    {
        if (a.a != b.a)
        {
            return a.a < b.a;
        }
        if (a.b != b.b)
        {
            return a.b < b.b;
        }
        if (a.c != b.c)
        {
            return a.c < b.c;
        }
        if (a.d != b.d)
        {
            return a.d < b.d;
        }
        return a.e < b.e;
    }
    std::set<IP> server;
    bool parse(std::string s, IP &res)
    {
        std::vector<int> cnt1, cnt2;
        cnt1.push_back(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                cnt1.push_back(i);
            }
            if (s[i] == ':')
            {
                cnt1.push_back(i);
                cnt2.push_back(i);
            }
        }
        if (cnt1.size() != 5)
        {
            return false;
        }
        if (cnt2.size() != 1)
        {
            return false;
        }
        if (cnt2[0] < cnt1[2])
        {
            return false;
        }
        int tmp[5];
        cnt1.push_back(s.size());
        for (int i = 0; i < cnt1.size() - 1; i++)
        {
            try
            {
                tmp[i] = std::stoi(s.substr(cnt1[i] + 1, cnt1[i + 1] - cnt1[i] - 1));
            }
            catch (const std::exception &e)
            {
                return false;
            }
            if (s.substr(cnt1[i] + 1, cnt1[i + 1] - cnt1[i] - 1).size() != 1 && s.substr(cnt1[i] + 1, cnt1[i + 1] - cnt1[i] - 1)[0] == '0')
            {
                return false;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (tmp[i] < 0 || tmp[i] > 255)
            {
                return false;
            }
        }
        if (tmp[4] < 0 || tmp[4] > 65535)
        {
            return false;
        }
        res.a = tmp[0], res.b = tmp[1], res.c = tmp[2], res.d = tmp[3], res.e = tmp[4];
        return true;
    }
    int main()
    {
        std::cin >> n;
        std::cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            IP u(i);
            std::string type, ip;
            std::cin >> type >> ip;
            if (parse(ip, u))
            {
                if (type == "Server")
                {
                    if (server.find(u) != server.end())
                    {
                        puts("FAIL");
                    }
                    else
                    {
                        server.insert(u);
                        puts("OK");
                    }
                }
                else
                {
                    if (server.find(u) != server.end())
                    {
                        printf("%d\n", server.find(u)->id);
                    }
                    else
                    {
                        puts("FAIL");
                    }
                }
            }
            else
            {
                puts("ERR");
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