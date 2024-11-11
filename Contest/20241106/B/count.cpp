#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=1e9+7;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int,int>pii;template<i64 MOD=MOD>class ModInt{public:i64 val;ModInt<MOD>(i64 x=0):val(x>=0?(x<MOD?x:x%MOD):(x%MOD+MOD)){}ModInt operator+(const ModInt a)const{return ModInt(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a)const{return ModInt(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a)const{return ModInt(val*a.val%MOD);}ModInt operator/(const ModInt a)const{return ModInt(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a)const{return ModInt(val&a.val);}ModInt operator|(const ModInt a)const{return ModInt((val|a.val)%MOD);}ModInt operator^(const ModInt a)const{return ModInt((val^a.val)%MOD);}ModInt operator<<(const ModInt a)const{return ModInt((val<<a.val)%MOD);}ModInt operator>>(const ModInt a)const{return ModInt(val>>a.val);}ModInt&operator++(){return val=val+1>=MOD?val+1-MOD:val+1,*this;}ModInt&operator+=(const ModInt a){return val=val+a.val>=MOD?val+a.val-MOD:val+a.val,*this;}ModInt&operator--(){return val=val-1>=0?val-1:val-1+MOD,*this;}ModInt&operator-=(const ModInt a){return val=val-a.val>=0?val-a.val:val-a.val+MOD,*this;}ModInt&operator*=(const ModInt a){return val=val*a.val%MOD,*this;}ModInt&operator/=(const ModInt a){return val=val*qpow(a,MOD-2).val%MOD,*this;}ModInt&operator&=(const ModInt a){return val=val&a.val,*this;}ModInt&operator|=(const ModInt a){return val=(val|a.val)%MOD,*this;}ModInt&operator^=(const ModInt a){return val=(val^a.val)%MOD,*this;}ModInt&operator<<=(const ModInt a){return val=(val<<a.val)%MOD,*this;}ModInt&operator>>=(const ModInt a){return val=val>>a.val,*this;}bol operator==(const ModInt&a)const{return val==a.val;}bol operator!=(const ModInt&a)const{return val!=a.val;}bol operator<(const ModInt&a)const{return val<a.val;}bol operator<=(const ModInt&a)const{return val<=a.val;}bol operator>(const ModInt&a)const{return val>a.val;}bol operator>=(const ModInt&a)const{return val>=a.val;}};template<i64 MOD=MOD>ModInt<MOD>qpow(ModInt<MOD>a,i64 b=MOD-2,i64 c=MOD){assert(c==MOD);ModInt<MOD>res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x.val);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    constexpr int MAXN = 6e2 + 5;

    int t;

    int n;

    i64 a[MAXN], b[MAXN], c[MAXN];

    i64 dp[2][MAXN][MAXN];

    bool check(i64 x)
    {
        i64 sqrt = std::sqrt(x);
        return sqrt * sqrt == x;
    }

    int fa[MAXN], size[MAXN];
    void init()
    {
        std::iota(fa + 1, fa + n + 1, 1);
        std::fill(size + 1, size + n + 1, 1);
    }
    int find(int x)
    {
        if (fa[x] == x)
        {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x != y)
        {
            fa[y] = x, size[x] += size[y];
        }
    }

    void add(i64 &x, i64 y)
    {
        x += y, x = x < MOD ? x : x - MOD;
    }

    int mian()
    {
        std::freopen("count.in", "r", stdin);
        std::freopen("count.out", "w", stdout);

        io.read(t);
        while (t--)
        {
            std::memset(dp, 0, sizeof(dp));

            io.read(n);
            io.reada(a + 1, a + n + 1);

            init();
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    if (check(a[i] * a[j]))
                    {
                        merge(i, j);
                    }
                }
            }

            b[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                if (fa[i] == i)
                {
                    for (int j = 1; j <= size[i]; j++)
                    {
                        b[++b[0]] = i;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                c[i] = (b[i] == b[i - 1] ? c[i - 1] : 0) + 1;
            }

            dp[1][0][2] = 1;
            for (int i = 1; i < n; i++)
            {
                std::memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
                for (int j = 0; j < i; j++)
                {
                    for (int k = c[i] + 1; k <= c[i] * 2 && j + k <= i + 1; k++)
                    {

                        if (b[i + 1] == b[i])
                        {
                            if (j > 0)
                            {
                                add(dp[i + 1 & 1][j - 1][k + 2], dp[i & 1][j][k] * j % MOD);
                            }
                            add(dp[i + 1 & 1][j][k + 1], dp[i & 1][j][k] * k % MOD);
                            add(dp[i + 1 & 1][j][k + 2], dp[i & 1][j][k] * (i + 1 - j - k) % MOD);
                        }
                        else
                        {
                            if (j + (c[i] * 2 - k) > 0)
                            {
                                add(dp[i + 1 & 1][j + (c[i] * 2 - k) - 1][2], dp[i & 1][j][k] * (j + (c[i] * 2 - k)) % MOD);
                            }
                            add(dp[i + 1 & 1][j + (c[i] * 2 - k)][2], dp[i & 1][j][k] * (i + 1 - j - (c[i] * 2 - k)) % MOD);
                        }
                    }
                }
            }

            io.writeln(dp[n & 1][0][c[n] * 2]);
        }

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
    return 0;
}