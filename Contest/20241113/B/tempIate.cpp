#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=998244353;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int,int>pii;template<i64 MOD=MOD>class ModInt{public:i64 val;ModInt<MOD>(i64 x=0):val(x>=0?(x<MOD?x:x%MOD):(x%MOD+MOD)){}ModInt operator+(const ModInt a)const{return ModInt(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a)const{return ModInt(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a)const{return ModInt(val*a.val%MOD);}ModInt operator/(const ModInt a)const{return ModInt(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a)const{return ModInt(val&a.val);}ModInt operator|(const ModInt a)const{return ModInt((val|a.val)%MOD);}ModInt operator^(const ModInt a)const{return ModInt((val^a.val)%MOD);}ModInt operator<<(const ModInt a)const{return ModInt((val<<a.val)%MOD);}ModInt operator>>(const ModInt a)const{return ModInt(val>>a.val);}ModInt&operator++(){return val=val+1>=MOD?val+1-MOD:val+1,*this;}ModInt&operator+=(const ModInt a){return val=val+a.val>=MOD?val+a.val-MOD:val+a.val,*this;}ModInt&operator--(){return val=val-1>=0?val-1:val-1+MOD,*this;}ModInt&operator-=(const ModInt a){return val=val-a.val>=0?val-a.val:val-a.val+MOD,*this;}ModInt&operator*=(const ModInt a){return val=val*a.val%MOD,*this;}ModInt&operator/=(const ModInt a){return val=val*qpow(a,MOD-2).val%MOD,*this;}ModInt&operator&=(const ModInt a){return val=val&a.val,*this;}ModInt&operator|=(const ModInt a){return val=(val|a.val)%MOD,*this;}ModInt&operator^=(const ModInt a){return val=(val^a.val)%MOD,*this;}ModInt&operator<<=(const ModInt a){return val=(val<<a.val)%MOD,*this;}ModInt&operator>>=(const ModInt a){return val=val>>a.val,*this;}bol operator==(const ModInt&a)const{return val==a.val;}bol operator!=(const ModInt&a)const{return val!=a.val;}bol operator<(const ModInt&a)const{return val<a.val;}bol operator<=(const ModInt&a)const{return val<=a.val;}bol operator>(const ModInt&a)const{return val>a.val;}bol operator>=(const ModInt&a)const{return val>=a.val;}};template<i64 MOD=MOD>ModInt<MOD>qpow(ModInt<MOD>a,i64 b=MOD-2,i64 c=MOD){assert(c==MOD);ModInt<MOD>res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x.val);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    constexpr int MAXP    = 11;
    constexpr int MAXN    = 1e5 + 5;
    constexpr int PRIME[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    constexpr int INF     = 0x3f3f3f3f;

    int n, q;

    struct Node
    {
        std::array<int, MAXP> cnt[2], tag;
    };
    Node operator+(const Node &a, const Node &b)
    {
        Node res;
        for (int i = 1; i < MAXP; i++)
        {
            res.tag[i]    = 0;
            res.cnt[0][i] = std::min(a.cnt[0][i], b.cnt[0][i]);
            res.cnt[1][i] = std::min(a.cnt[1][i], b.cnt[1][i]);
        }
        return res;
    }

    Node node[MAXN << 2];
    void init(int o)
    {
        std::fill(node[o].cnt[0].begin(), node[o].cnt[0].end(), INF);
        std::fill(node[o].cnt[1].begin(), node[o].cnt[1].end(), 0);
        std::fill(node[o].tag.begin(), node[o].tag.end(), 0);
    }
    void pushup(int o)
    {
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void modify_c(int o)
    {
        std::swap(node[o].cnt[0], node[o].cnt[1]);
    }
    void modify_v(int o, std::array<int, MAXP> &x)
    {
        for (int i = 1; i < MAXP; i++)
        {
            node[o].cnt[1][i] += x[i], node[o].tag[i] += x[i];
        }
    }
    void pushdown(int o)
    {
        modify_v(o << 1, node[o].tag), modify_v(o << 1 | 1, node[o].tag);
        std::fill(node[o].tag.begin(), node[o].tag.end(), 0);
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r) return init(o);

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        pushup(o);
    }
    void update_c(int x, int o = 1, int l = 1, int r = n)
    {
        if (l == r) return modify_c(o);

        pushdown(o);

        int mid = (l + r) >> 1;
        if (x <= mid) update_c(x, o << 1, l, mid);
        if (x > mid) update_c(x, o << 1 | 1, mid + 1, r);

        pushup(o);
    }
    void update_v(int ql, int qr, std::array<int, MAXP> &x, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr) return modify_v(o, x);

        pushdown(o);

        int mid = (l + r) >> 1;
        if (ql <= mid) update_v(ql, qr, x, o << 1, l, mid);
        if (qr > mid) update_v(ql, qr, x, o << 1 | 1, mid + 1, r);

        pushup(o);
    }
    Node query_v(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr) return node[o];

        pushdown(o);

        int mid = (l + r) >> 1;
        if (qr <= mid) return query_v(ql, qr, o << 1, l, mid);
        if (ql > mid) return query_v(ql, qr, o << 1 | 1, mid + 1, r);

        return query_v(ql, qr, o << 1, l, mid) + query_v(ql, qr, o << 1 | 1, mid + 1, r);
    }

    int mian()
    {
        std::freopen("tempIate.in", "r", stdin);
        std::freopen("tempIate.out", "w", stdout);

        io.read(n, q);

        build();
        for (int id = 1; id <= q; id++)
        {
            int op = io.readi();
            if (op == 1)
            {
                int x = io.readi();
                update_c(x);
            }
            if (op == 2)
            {
                int l = io.readi(), r = io.readi(), x = io.readi();
                std::array<int, MAXP> v = {};
                for (int i = 1; i < MAXP; i++)
                {
                    while (x % PRIME[i] == 0) v[i]++, x /= PRIME[i];
                }
                update_v(l, r, v);
            }
            if (op == 3)
            {
                int l = io.readi(), r = io.readi(), x = io.readi();
                std::array<int, MAXP> v = {};
                for (int i = 1; i < MAXP; i++)
                {
                    while (x % PRIME[i] == 0) v[i]++, x /= PRIME[i];
                }
                auto res = query_v(l, r);

                bool flag = true;
                for (int i = 1; i < MAXP; i++)
                {
                    if (res.cnt[0][i] < v[i] || res.cnt[1][i] < v[i])
                    {
                        flag = false;
                        break;
                    }
                    v[i] = -v[i];
                }

                if (flag == true) io.writeln("YES"), update_v(l, r, v);
                if (flag == false) io.writeln("NO");
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