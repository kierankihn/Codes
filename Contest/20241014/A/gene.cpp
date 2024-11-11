#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=998244353;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int,int>pii;template<i64 MOD=MOD>class ModInt{public:i64 val;ModInt<MOD>(i64 x=0):val(x>=0?(x<MOD?x:x%MOD):(x%MOD+MOD)){}ModInt operator+(const ModInt a)const{return ModInt(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a)const{return ModInt(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a)const{return ModInt(val*a.val%MOD);}ModInt operator/(const ModInt a)const{return ModInt(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a)const{return ModInt(val&a.val);}ModInt operator|(const ModInt a)const{return ModInt((val|a.val)%MOD);}ModInt operator^(const ModInt a)const{return ModInt((val^a.val)%MOD);}ModInt operator<<(const ModInt a)const{return ModInt((val<<a.val)%MOD);}ModInt operator>>(const ModInt a)const{return ModInt(val>>a.val);}ModInt&operator++(){return val=val+1>=MOD?val+1-MOD:val+1,*this;}ModInt&operator+=(const ModInt a){return val=val+a.val>=MOD?val+a.val-MOD:val+a.val,*this;}ModInt&operator--(){return val=val-1>=0?val-1:val-1+MOD,*this;}ModInt&operator-=(const ModInt a){return val=val-a.val>=0?val-a.val:val-a.val+MOD,*this;}ModInt&operator*=(const ModInt a){return val=val*a.val%MOD,*this;}ModInt&operator/=(const ModInt a){return val=val*qpow(a,MOD-2).val%MOD,*this;}ModInt&operator&=(const ModInt a){return val=val&a.val,*this;}ModInt&operator|=(const ModInt a){return val=(val|a.val)%MOD,*this;}ModInt&operator^=(const ModInt a){return val=(val^a.val)%MOD,*this;}ModInt&operator<<=(const ModInt a){return val=(val<<a.val)%MOD,*this;}ModInt&operator>>=(const ModInt a){return val=val>>a.val,*this;}bol operator==(const ModInt&a)const{return val==a.val;}bol operator!=(const ModInt&a)const{return val!=a.val;}bol operator<(const ModInt&a)const{return val<a.val;}bol operator<=(const ModInt&a)const{return val<=a.val;}bol operator>(const ModInt&a)const{return val>a.val;}bol operator>=(const ModInt&a)const{return val>=a.val;}};template<i64 MOD=MOD>ModInt<MOD>qpow(ModInt<MOD>a,i64 b=MOD-2,i64 c=MOD){assert(c==MOD);ModInt<MOD>res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x.val);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    typedef pair<pii, pii> p4i;

    constexpr int P    = 1e7;
    constexpr int MAXC = 5;
    constexpr int MAXN = 1e5 + 5;
    constexpr int MAXP = 1e7 + 5;

    int n, q;
    std::string a[MAXN];

    int get(chr x)
    {
        if (x == 'A') return 0;
        if (x == 'G') return 1;
        if (x == 'U') return 2;
        if (x == 'C') return 3;
        assert(false);
    }

    int size_trie[2];
    int son[2][MAXP][MAXC];
    void insert(std::string &s, int x)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (son[x][u][get(s[i])] == 0)
            {
                son[x][u][get(s[i])] = ++size_trie[x];
            }
            u = son[x][u][get(s[i])];
        }
    }

    pii p[MAXN];
    int size_dfn[2], dfn[2][MAXP], start[2][MAXP], end[2][MAXP];
    void dfs(int u, int x)
    {
        dfn[x][u] = start[x][u] = ++size_dfn[x];

        for (int i = 0; i < 4; i++)
        {
            if (son[x][u][i] != 0)
            {
                dfs(son[x][u][i], x);
            }
        }

        end[x][u] = size_dfn[x];
    }

    int find(std::string &s, int x)
    {
        int u = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (son[x][u][get(s[i])] == 0)
            {
                return -1;
            }
            u = son[x][u][get(s[i])];
        }
        return u;
    }

    int ans[MAXN];

    std::vector<p4i> que;

    int sum[MAXP];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, int v)
    {
        while (x <= P)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    int query(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    int mian()
    {
        std::freopen("gene.in", "r", stdin);
        std::freopen("gene.out", "w", stdout);

        io.read(n, q);
        io.reada(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            insert(a[i], 0), std::reverse(a[i].begin(), a[i].end()), insert(a[i], 1);
        }

        dfs(0, 0), dfs(0, 1);

        for (int i = 1; i <= n; i++)
        {
            p[i].se = dfn[1][find(a[i], 1)], std::reverse(a[i].begin(), a[i].end()), p[i].fi = dfn[0][find(a[i], 0)];
        }

        for (int i = 1; i <= q; i++)
        {
            auto s = io.reads(), t = io.reads();

            std::reverse(t.begin(), t.end());
            auto x = find(s, 0), y = find(t, 1);

            if (x != -1 && y != -1)
            {
                que.push_back({{start[0][x] - 1, start[1][y] - 1}, {1, i}});
                que.push_back({{start[0][x] - 1, end[1][y]}, {-1, i}});
                que.push_back({{end[0][x], start[1][y] - 1}, {-1, i}});
                que.push_back({{end[0][x], end[1][y]}, {1, i}});
            }
        }

        std::sort(que.begin(), que.end());
        std::sort(p + 1, p + n + 1);

        for (int i = 1, j = 0; j < que.size(); j++)
        {
            while (i <= n && p[i].fi <= que[j].fi.fi)
            {
                update(p[i].se, 1), i++;
            }
            ans[que[j].se.se] += query(que[j].fi.se) * que[j].se.fi;
        }

        for (int i = 1; i <= q; i++)
        {
            io.writeln(ans[i]);
        }

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
    return 0;
}