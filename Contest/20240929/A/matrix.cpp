#include <bits/stdc++.h>

namespace utils
{
    typedef bool bol;
    typedef char chr;
    typedef double dbi;
    typedef long long i64;
    typedef __int128 i128;
    typedef std::pair<i64, i64> pii;

    constexpr dbi EPS  = 1e-8;
    constexpr int MOD  = 998244353;
    constexpr int MAXN = 2e3 + 5;
} // namespace utils

// clang-format off
namespace utils{template<typename T>T qpow(T a,i64 b=MOD-2){T res=1;while(b){if(b&1){res*=a;}a*=a,b>>=1;}return res;}template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){T res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}template<typename T>T max(const T x,const T y){return x>=y?x:y;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair&a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair&a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair&a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair&a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair&a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair&a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};template<i64 MOD=MOD>class ModInt{private:i64 val;ModInt<MOD>&setValue(i64 x){return val=x,*this;}public:ModInt<MOD>():val(0){}ModInt<MOD>(i64 x):val((x%MOD+MOD)%MOD){}operator i64()const{return val;}ModInt operator+(const ModInt a){return ModInt().setValue(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a){return ModInt().setValue(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a){return ModInt().setValue(val*a.val%MOD);}ModInt operator/(const ModInt a){return ModInt().setValue(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a){return ModInt().setValue(val&a.val);}ModInt operator|(const ModInt a){return ModInt().setValue((val|a.val)%MOD);}ModInt operator^(const ModInt a){return ModInt().setValue((val^a.val)%MOD);}ModInt operator<<(const ModInt a){return ModInt().setValue((val<<a.val)%MOD);}ModInt operator>>(const ModInt a){return ModInt().setValue(val>>a.val);}ModInt&operator+=(const ModInt a){return setValue(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt&operator-=(const ModInt a){return setValue(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt&operator*=(const ModInt a){return setValue(val*a.val%MOD);}ModInt&operator/=(const ModInt a){return setValue(val*qpow(a,MOD-2).val%MOD);}ModInt&operator&=(const ModInt a){return setValue(val&a.val);}ModInt&operator|=(const ModInt a){return setValue((val|a.val)%MOD);}ModInt&operator^=(const ModInt a){return setValue((val^a.val)%MOD);}ModInt&operator<<=(const ModInt a){return setValue((val<<a.val)%MOD);}ModInt&operator>>=(const ModInt a){return setValue(val>>a.val);}};typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>&x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First&first,Rest&...rest){write(first),putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First&first,Rest&...rest){write(first,rest...),putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),putchar('\n');}}io;}
// clang-format on

namespace solution
{
    using namespace utils;

    int n, q;

    i64 ans = 0;

    i64 a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN], d[MAXN][MAXN];

    int mian()
    {
        std::freopen("matrix.in", "r", stdin);
        std::freopen("matrix.out", "w", stdout);

        io.read(n, q);

        for (int i = 1; i <= q; i++)
        {
            int x = io.readi(), y = io.readi(), len = io.readi(), s = io.readi();
            c[x][y] += s, c[x + len][y] -= s;
            d[x][y + 1] -= s, d[x + len][y + len + 1] += s;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                c[i][j] += c[i - 1][j];
            }
        }

        for (int id = 1; id <= n; id++)
        {
            for (int x = 1, y = id; x <= n && y <= n; x++, y++)
            {
                d[x][y] += d[x - 1][y - 1];
            }
        }
        for (int id = 2; id <= n; id++)
        {
            for (int x = id, y = 1; x <= n && y <= n; x++, y++)
            {
                d[x][y] += d[x - 1][y - 1];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                b[i][j] = c[i][j] + d[i][j];
                a[i][j] = a[i][j - 1] + b[i][j];

                ans ^= a[i][j];
            }
        }

        io.write(ans);

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
}