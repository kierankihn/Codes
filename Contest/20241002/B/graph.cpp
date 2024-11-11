#include <bits/stdc++.h>

namespace solution
{
    // clang-format off
    typedef bool bol;typedef char chr;typedef double dbi;typedef long long i64;typedef __int128 i128;constexpr dbi EPS=1e-8;constexpr int MOD=1e9 + 7;template<typename T>T qpow(T a,i64 b=MOD-2,i64 c=MOD){i64 res=1;while(b){if(b&1){res*=a,res%=c;}a*=a,a%=c,b>>=1;}return res;}int qpow(int a,i64 b=MOD-2,i64 c=MOD){i64 res=1;while(b){if(b&1){res*=a,res%=c;}a=1LL*a*a%c,b>>=1;}return res;}template<typename T>T max(const T x,const T y){return x>=y?x:y;}template<typename T>T&cmax(T&x,const T y){return x>=y?x:x=y;}template<typename T>T min(const T x,const T y){return x<=y?x:y;}template<typename T>T&cmin(T&x,const T y){return x<=y?x:x=y;}template<typename T>T abs(T x){return x>=0?x:-x;}i64 floor(dbi x){return x+EPS;}i64 ceil(dbi x){return x-EPS+1;}template<typename T1,typename T2>struct pair{T1 fi;T2 se;bol operator==(const pair a)const{return fi==a.fi&&se==a.se;}bol operator!=(const pair a)const{return fi!=a.fi||se!=a.se;}bol operator<(const pair a)const{return fi!=a.fi?fi<a.fi:se<a.se;}bol operator<=(const pair a)const{return fi!=a.fi?fi<=a.fi:se<=a.se;}bol operator>(const pair a)const{return fi!=a.fi?fi>a.fi:se>a.se;}bol operator>=(const pair a)const{return fi!=a.fi?fi>=a.fi:se>=a.se;}};typedef pair<int, int> pii;template<i64 MOD=MOD>class ModInt{private:i64 val;ModInt<MOD>&setValue(i64 x){return val=x,*this;}public:ModInt<MOD>():val(0){}ModInt<MOD>(i64 x):val((x%MOD+MOD)%MOD){}operator i64()const{return val;}ModInt operator+(const ModInt a){return ModInt().setValue(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt operator-(const ModInt a){return ModInt().setValue(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt operator*(const ModInt a){return ModInt().setValue(val*a.val%MOD);}ModInt operator/(const ModInt a){return ModInt().setValue(val*qpow(a,MOD-2).val%MOD);}ModInt operator&(const ModInt a){return ModInt().setValue(val&a.val);}ModInt operator|(const ModInt a){return ModInt().setValue((val|a.val)%MOD);}ModInt operator^(const ModInt a){return ModInt().setValue((val^a.val)%MOD);}ModInt operator<<(const ModInt a){return ModInt().setValue((val<<a.val)%MOD);}ModInt operator>>(const ModInt a){return ModInt().setValue(val>>a.val);}ModInt&operator+=(const ModInt a){return setValue(val+a.val>=MOD?val+a.val-MOD:val+a.val);}ModInt&operator-=(const ModInt a){return setValue(val-a.val>=0?val-a.val:val-a.val+MOD);}ModInt&operator*=(const ModInt a){return setValue(val*a.val%MOD);}ModInt&operator/=(const ModInt a){return setValue(val*qpow(a,MOD-2).val%MOD);}ModInt&operator&=(const ModInt a){return setValue(val&a.val);}ModInt&operator|=(const ModInt a){return setValue((val|a.val)%MOD);}ModInt&operator^=(const ModInt a){return setValue((val^a.val)%MOD);}ModInt&operator<<=(const ModInt a){return setValue((val<<a.val)%MOD);}ModInt&operator>>=(const ModInt a){return setValue(val>>a.val);}};typedef ModInt<MOD>moi;class IO{public:i64 readi(){chr ch;i64 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}i128 readi128(){chr ch;i128 res=0,f=1;while(std::isdigit(ch=std::getchar())==false){f=(ch!='-');}do{res=res*10+(ch-'0');}while(std::isdigit(ch=std::getchar())==true);return res*(f?1:-1);}chr readc(){chr res=std::getchar();while(res==' '||res=='\n'){res=std::getchar();}return res;}std::string reads(){std::string res;std::cin>>res;return res;}template<typename T>T&read(T&x){return std::cin>>x,x;}int&read(int&x){return x=readi();}i64&read(i64&x){return x=readi();}i128&read(i128&x){return x=readi128();}template<i64 MOD=MOD>ModInt<MOD>&read(ModInt<MOD>&x){return x=readi();}chr&read(chr&x){return x=readc();}dbi&read(dbi&x){return scanf("%lf",&x),x;}template<typename T1,typename T2>pair<T1,T2>&read(pair<T1,T2>&x){return read(x.fi),read(x.se),x;}template<typename First,typename...Rest>void read(First&first,Rest&...rest){read(first);read(rest...);}template<typename T>void reada(T begin,T end){for(T iter=begin;iter!=end;iter++){read(*iter);}}void writei(i64 x){if(x<0){std::putchar('-'),writei(-x);return;}if(x>=10){writei(x/10);}std::putchar(x%10+'0');}void writei128(i128 x){if(x<0){std::putchar('-'),writei128(-x);return;}if(x>=10){writei128(x/10);}std::putchar(x%10+'0');}void writec(char x){std::putchar(x);}void writed(dbi x){printf("%lf",x);}template<typename T>void write(T x){std::cout<<x;}void write(int x){writei(x);}void write(i64 x){writei(x);}void write(i128 x){writei128(x);}template<i64 MOD=MOD>void write(ModInt<MOD>x){writei(x);}void write(char x){writec(x);}void write(dbi x){writed(x);}template<typename T1,typename T2>void write(pair<T1,T2>x){write(x.fi),std::putchar(' '),write(x.se);}template<typename First,typename...Rest>void write(First first,Rest...rest){write(first),std::putchar(' ');write(rest...);}template<typename First,typename...Rest>void writeln(First first,Rest...rest){write(first,rest...),std::putchar('\n');}template<typename T>void writea(T begin,T end){for(T iter=begin;iter!=end;iter++){write(*iter),std::putchar(' ');}}template<typename T>void writealn(T begin,T end){writea(begin,end),std::putchar('\n');}}io;
    // clang-format on

    constexpr int MAXN  = 1e2 + 5;
    constexpr int MAX2D = (1 << 22) + 5;

    int n, m, d;

    std::vector<pair<int, int>> e[MAXN];

    int size = 1;
    int son[MAX2D][2], cnt[MAX2D];

    std::bitset<MAX2D> vis[MAXN];
    void dfs(int u, int dep, int ut)
    {
        if (vis[u][ut] == true || dep == d + 1 || cnt[ut] + 1 == 1 << (d - dep + 1))
        {
            return;
        }

        vis[u][ut] = true;

        for (auto edge : e[u])
        {
            int v = edge.fi, w = edge.se;
            if (son[ut][w] == 0)
            {
                son[ut][w] = ++size;
            }
            dfs(v, dep + 1, son[ut][w]);
        }

        cnt[ut] = 1 + cnt[son[ut][0]] + cnt[son[ut][1]];
    }

    int ans = 0;
    void solve(int u, int dep)
    {
        if (u == 0)
        {
            return;
        }
        if (dep == d)
        {
            ans++;
            return;
        }

        solve(son[u][0], dep + 1), solve(son[u][1], dep + 1);
    }

    int mian()
    {
        std::freopen("graph.in", "r", stdin);
        std::freopen("graph.out", "w", stdout);

        io.read(n, m, d);

        for (int i = 1; i <= m; i++)
        {
            int u = io.readi(), v = io.readi(), w = io.readi();
            e[u].push_back({v, w}), e[v].push_back({u, w});
        }

        dfs(1, 0, 1);
        solve(1, 0);

        io.writeln(ans);

        return 0;
    }
} // namespace solution

int main()
{
    solution::mian();
}