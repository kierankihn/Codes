#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    constexpr int MAXN = 1e6 + 5;
    
    int n;
    
    char s[MAXN];
    
    int suml[MAXN], sumr[MAXN];
    
    int ans[MAXN];

    int main()
    {
        freopen("ant.in", "r", stdin);
        freopen("ant.out", "w", stdout);

        read(n, s);
        for (int i = 1; i <= n; i++)
        {
        	sumr[i] = sumr[i - 1] + (s[i - 1] == 'P');
		}
		for (int i = n; i >= 1; i--)
		{
			suml[i] = suml[i + 1] + (s[i - 1] == 'L');
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == 'L')
			{
				if (sumr[i - 1] > suml[i + 1])
				{
					ans[i] = suml[i + 1] * 2 + 1;
				}
				else
				{
					ans[i] = sumr[i - 1] * 2;
				}
			}
			else
			{
				if (suml[i + 1] > sumr[i - 1])
				{
					ans[i] = sumr[i - 1] * 2 + 1;
				}
				else
				{
					ans[i] = suml[i + 1] * 2;
				}
			}
		}
		
		writeAll(ans + 1, ans + n + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}
