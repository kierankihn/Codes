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

    constexpr int INF  = 0x3f3f3f3f;
    constexpr int MAXN = 1e5 + 5;
    constexpr int K    = 20;
    
    int n;
    
    int a[MAXN];
    
    int extend(int l, int r, int v, int limitl = 1, int limitr = n)
    {
    	int res = v;
    	if (l != limitl && a[l - 1] == v + 1)
    	{
    		res = std::max(res, extend(l - 1, r, v + 1, limitl, limitr));
		}
		if (r != limitr && a[r + 1] == v + 1)
		{
			res = std::max(res, extend(l, r + 1, v + 1, limitl, limitr));
		}
		return res;
	}
	int calc(int l, int r, int limitl, int limitr)
	{
		int res = 0;
		for (int i = l; i < r; i++)
		{
			if (a[i] == a[i + 1])
			{
				res = std::max(res, extend(i, i + 1, a[i], limitl, limitr));
			}
		}
		return res;
	}
	
	struct Node
	{
		int max, ext;
	};
	Node operator+(const Node &a, const Node &b)
	{
		return {std::max(a.max, b.max), std::max(a.ext, b.ext)};
	}
	
	Node node[MAXN << 2];
	void update(int x, int v_max, int v_ext, int o = 1, int l = 1, int r = n)
	{
		if (l == r)
		{
			node[o] = {v_max, v_ext};
			return;
		}
		
		int mid = (l + r) >> 1;
		if (x <= mid)
		{
			update(x, v_max, v_ext, o << 1, l, mid);
		}
		if (x > mid)
		{
			update(x, v_max, v_ext, o << 1 | 1, mid + 1, r);
		}
		
		node[o] = node[o << 1] + node[o << 1 | 1];
	}
	Node query(int ql, int qr, int o = 1, int l = 1, int r = n)
	{
		if (ql <= l && r <= qr)
		{
			return node[o];
		}
		
		int mid = (l + r) >> 1;
		if (mid >= ql && mid < qr)
		{
			return query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r);
		}
		if (mid >= qr)
		{
			return query(ql, qr, o << 1, l, mid);
		}
		if (mid < qr)
		{
			return query(ql, qr, o << 1 | 1, mid + 1, r);
		}
		
		return {-INF, -INF};
	}
	
	int solve(int l, int r)
	{
		int res = query(l, r).max;
		
		res = std::max(res, calc(l, l + K - 1, l, r));
		res = std::max(res, calc(r - K + 1, r, l, r));
		
		if (l + K - 1 <= r - K + 1)
		{
			res = std::max(res, query(l + K - 1, r - K + 1).ext);
		}
		
		return res;
	}

    int main()
    {
//        freopen("remove.in", "r", stdin);
//        freopen("remove.out", "w", stdout);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}
