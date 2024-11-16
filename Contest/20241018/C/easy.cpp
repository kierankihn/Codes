#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=998244353;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int,int>pii;template<i64 MOD=MOD>class ModInt{public:i64 val;ModInt<MOD>(i64 x=0):val(x>=0?(x<MOD?x:x%MOD):(x%MOD+MOD)){}ModInt operator+(const ModInt a)const{return ModInt(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a)const{return ModInt(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a)const{return ModInt(val*a.val%MOD);}ModInt operator/(const ModInt a)const{return ModInt(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a)const{return ModInt(val&a.val);}ModInt operator|(const ModInt a)const{return ModInt((val|a.val)%MOD);}ModInt operator^(const ModInt a)const{return ModInt((val^a.val)%MOD);}ModInt operator<<(const ModInt a)const{return ModInt((val<<a.val)%MOD);}ModInt operator>>(const ModInt a)const{return ModInt(val>>a.val);}ModInt&operator++(){return val=val+1>=MOD?val+1-MOD:val+1,*this;}ModInt&operator+=(const ModInt a){return val=val+a.val>=MOD?val+a.val-MOD:val+a.val,*this;}ModInt&operator--(){return val=val-1>=0?val-1:val-1+MOD,*this;}ModInt&operator-=(const ModInt a){return val=val-a.val>=0?val-a.val:val-a.val+MOD,*this;}ModInt&operator*=(const ModInt a){return val=val*a.val%MOD,*this;}ModInt&operator/=(const ModInt a){return val=val*qpow(a,MOD-2).val%MOD,*this;}ModInt&operator&=(const ModInt a){return val=val&a.val,*this;}ModInt&operator|=(const ModInt a){return val=(val|a.val)%MOD,*this;}ModInt&operator^=(const ModInt a){return val=(val^a.val)%MOD,*this;}ModInt&operator<<=(const ModInt a){return val=(val<<a.val)%MOD,*this;}ModInt&operator>>=(const ModInt a){return val=val>>a.val,*this;}bol operator==(const ModInt&a)const{return val==a.val;}bol operator!=(const ModInt&a)const{return val!=a.val;}bol operator<(const ModInt&a)const{return val<a.val;}bol operator<=(const ModInt&a)const{return val<=a.val;}bol operator>(const ModInt&a)const{return val>a.val;}bol operator>=(const ModInt&a)const{return val>=a.val;}};template<i64 MOD=MOD>ModInt<MOD>qpow(ModInt<MOD>a,i64 b=MOD-2,i64 c=MOD){assert(c==MOD);ModInt<MOD>res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x.val);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    constexpr int MAXN = 10 + 5;
    constexpr int MAXP = MAXN * 12;

    int n;
    int a[MAXN], pos[MAXN];

    std::vector<int> e[MAXN];

    i64 calc(i64 x)
    {
        return x * (x - 1) / 2 + x;
    }

    struct Node
    {
        i64 sum;
        int lcnt, rcnt, lson, rson;
    };

    int root[MAXN];
    Node node[MAXP];

    int use[MAXP], not_used[MAXP];
    void del(int x)
    {
        if (x == 0)
        {
            return;
        }
        if (--use[x] <= 0)
        {
            del(node[x].lson), del(node[x].rson);
            not_used[++not_used[0]] = x, use[x] = 0, node[x] = {0, 0, 0, 0, 0};
        }
    }

    void pushup(int o, int l, int r)
    {
        auto &lson = node[node[o].lson], &rson = node[node[o].rson];
        node[o] = {lson.sum + rson.sum, lson.lcnt, rson.rcnt, node[o].lson, node[o].rson};

        node[o].sum += calc(lson.rcnt + rson.lcnt) - calc(lson.rcnt) - calc(rson.lcnt);

        int mid = (l + r) >> 1;
        if (lson.lcnt == mid - l + 1) { node[o].lcnt = lson.lcnt + rson.lcnt; }
        if (rson.rcnt == r - mid) { node[o].rcnt = rson.rcnt + lson.rcnt; }
    }
    void update(int x, int &o, int l = 1, int r = n)
    {
        if (o == 0)
        {
            use[o = not_used[not_used[0]--]]++;
        }
        if (l == r)
        {
            node[o].sum = node[o].lcnt = node[o].rcnt = 1;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            update(x, node[o].rson, mid + 1, r);
        }

        pushup(o, l, r);
    }
    void merge(int &o1, int &o2, int l = 1, int r = n)
    {
        if (o1 == 0 || o2 == 0)
        {
            return void(use[o1 = o2 = o1 | o2]++);
        }

        int mid = (l + r) >> 1;

        merge(node[o1].lson, node[o2].lson, l, mid);
        merge(node[o1].rson, node[o2].rson, mid + 1, r);

        pushup(o1, l, r);
    }

    i64 ans = 0;

    int dep[MAXN];
    i64 solve(int u, int fa)
    {
        update(pos[u], root[u]), dep[u] = dep[fa] + 1;

        i64 sum = 0, res = 0;
        for (auto v : e[u])
        {
            if (v != fa)
            {
                res -= solve(v, u), merge(root[u], root[v]);
            }
        }

        res += (sum = node[root[u]].sum), ans += res * dep[u];

        del(root[u]);

        return sum;
    }

    int mian()
    {
        std::freopen("easy.in", "r", stdin);
        std::freopen("easy.out", "w", stdout);

        for (int i = 1; i < MAXP; i++)
        {
            not_used[++not_used[0]] = i;
        }

        io.read(n);
        for (int i = 1; i < n; i++)
        {
            int u = io.readi(), v = io.readi();
            e[u].push_back(v), e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            pos[a[i] = io.readi()] = i;
        }

        solve(1, 0);

        io.writeln(ans);

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
    return 0;
}