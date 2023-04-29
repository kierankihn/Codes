#include <bits/stdc++.h>
using namespace std;
const int MAXN=10+2;
int n,k,t;
long long ans;
long long dp[MAXN][1<<MAXN][MAXN*MAXN];
vector<pair<int,int>> situ;
inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(long long x)
{
    if (x < 0)
    {
        putchar('-'), x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}
int getOneNumber(int x)
{
	int res=0;
	while(x)
	{
		if(x&1)
		{
			res++;
		}
		x=x>>1;
	}
	return res;
}
int main()
{
	n=readInt();
	k=readInt();
	for(int i=0;i<(1<<n);i++)
	{
		if(i&(i<<1))
		{
			continue;
		}
		situ.push_back(pair<int,int>(i,getOneNumber(i)));
	}
	dp[0][0][0]=1;
	t=situ.size();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<t;j++)
		{
			for(int p=0;p<t;p++)
			{
				int sit1,sit2;
				sit1=situ[j].first;
				sit2=situ[p].first;
				if(sit1&sit2)
				{
					continue;
				}
				if(sit1&(sit2<<1))
				{
					continue;
				}
				if(sit1&(sit2>>1))
				{
					continue;
				}
				for(int q=0;q<=k;q++)
				{
					if(q-situ[j].second>=0)
					{
						dp[i][sit1][q]+=dp[i-1][sit2][q-situ[j].second];
					}
				}
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		ans+=dp[n][situ[i].first][k];
	}
	cout << ans << endl;
	return 0;
}
