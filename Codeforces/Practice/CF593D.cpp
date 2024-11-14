#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=998244353;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int,int>pii;template<i64 MOD=MOD>class ModInt{public:i64 val;ModInt<MOD>(i64 x=0):val(x>=0?(x<MOD?x:x%MOD):(x%MOD+MOD)){}ModInt operator+(const ModInt a)const{return ModInt(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a)const{return ModInt(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a)const{return ModInt(val*a.val%MOD);}ModInt operator/(const ModInt a)const{return ModInt(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a)const{return ModInt(val&a.val);}ModInt operator|(const ModInt a)const{return ModInt((val|a.val)%MOD);}ModInt operator^(const ModInt a)const{return ModInt((val^a.val)%MOD);}ModInt operator<<(const ModInt a)const{return ModInt((val<<a.val)%MOD);}ModInt operator>>(const ModInt a)const{return ModInt(val>>a.val);}ModInt&operator++(){return val=val+1>=MOD?val+1-MOD:val+1,*this;}ModInt&operator+=(const ModInt a){return val=val+a.val>=MOD?val+a.val-MOD:val+a.val,*this;}ModInt&operator--(){return val=val-1>=0?val-1:val-1+MOD,*this;}ModInt&operator-=(const ModInt a){return val=val-a.val>=0?val-a.val:val-a.val+MOD,*this;}ModInt&operator*=(const ModInt a){return val=val*a.val%MOD,*this;}ModInt&operator/=(const ModInt a){return val=val*qpow(a,MOD-2).val%MOD,*this;}ModInt&operator&=(const ModInt a){return val=val&a.val,*this;}ModInt&operator|=(const ModInt a){return val=(val|a.val)%MOD,*this;}ModInt&operator^=(const ModInt a){return val=(val^a.val)%MOD,*this;}ModInt&operator<<=(const ModInt a){return val=(val<<a.val)%MOD,*this;}ModInt&operator>>=(const ModInt a){return val=val>>a.val,*this;}bol operator==(const ModInt&a)const{return val==a.val;}bol operator!=(const ModInt&a)const{return val!=a.val;}bol operator<(const ModInt&a)const{return val<a.val;}bol operator<=(const ModInt&a)const{return val<=a.val;}bol operator>(const ModInt&a)const{return val>a.val;}bol operator>=(const ModInt&a)const{return val>=a.val;}};template<i64 MOD=MOD>ModInt<MOD>qpow(ModInt<MOD>a,i64 b=MOD-2,i64 c=MOD){assert(c==MOD);ModInt<MOD>res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x.val);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    typedef pair<i64, i64> pll;
    typedef pair<pll, i64> p3i;

#ifdef LOCAL
    constexpr int MAXN = 100;
#else
    constexpr int MAXN = 2e5 + 5;
#endif
    constexpr i128 INF = 2e18L;

    int n, q;
    i64 a[MAXN], id[MAXN];

    p3i edge[MAXN];

    std::vector<pll> e[MAXN];

    int fa[MAXN], size[MAXN], dep[MAXN], son[MAXN], dfn[MAXN], rank[MAXN], top[MAXN];
    int dfs1(int u, int father)
    {
        fa[u] = father, size[u] = 1, dep[u] = dep[father] + 1;
        for (auto [v, w] : e[u])
        {
            if (v != father)
            {
                size[u] += dfs1(v, u);
                son[u] = size[v] > size[son[u]] ? v : son[u];
            }
        }
        return size[u];
    }
    void dfs2(int u, int topu)
    {
        dfn[u] = ++dfn[0], rank[dfn[u]] = u, top[u] = topu;
        if (son[u] != 0) dfs2(son[u], top[u]);
        for (auto [v, w] : e[u])
        {
            if (v != fa[u] && v != son[u])
            {
                dfs2(v, v);
            }
        }
    }

    struct Node
    {
        i64 mul = 1;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {i64(std::min(i128(1) * a.mul * b.mul, INF))};
    }

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r) return node[o].mul = a[l], void();

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int x, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (l == r) return node[o].mul = v, void();

        int mid = (l + r) >> 1;
        if (x <= mid) update(x, v, o << 1, l, mid);
        if (x > mid) update(x, v, o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    Node query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql > qr) return {1};
        if (ql <= l && r <= qr) return node[o];

        int mid = (l + r) >> 1;
        if (qr <= mid) return query(ql, qr, o << 1, l, mid);
        if (ql > mid) return query(ql, qr, o << 1 | 1, mid + 1, r);

        return query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r);
    }

    i64 solve(int x, int y)
    {
        Node res;
        while (top[x] != top[y])
        {
            if (dep[top[x]] >= dep[top[y]])
            {
                res = res + query(dfn[top[x]], dfn[x]), x = fa[top[x]];
            }
            else
            {
                res = res + query(dfn[top[y]], dfn[y]), y = fa[top[y]];
            }
        }

        res = res + query(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]));

        return res.mul;
    }

    int mian()
    {
        io.read(n, q);
        for (int i = 1; i < n; i++)
        {
            i64 u = io.readi(), v = io.readi(), w = io.readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
            edge[i] = {{u, v}, w};
        }

        dfs1(1, 0), dfs2(1, 1);

        for (int i = 1; i < n; i++)
        {
            i64 u = edge[i].fi.fi, v = edge[i].fi.se, w = edge[i].se;
            a[id[i] = dfn[fa[v] == u ? v : u]] = w;
        }

        build();
        for (int i = 1; i <= q; i++)
        {
            int op = io.readi();
            if (op == 1)
            {
                i64 u = io.readi(), v = io.readi(), x = io.readi();
                io.writeln(x / solve(u, v));
            }
            if (op == 2)
            {
                i64 x = io.readi(), w = io.readi();
                update(id[x], w);
            }
        }

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
    return 0;
}