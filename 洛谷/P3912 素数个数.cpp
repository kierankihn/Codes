#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5;
int n;
int prime[MAXN];
bool notprime[MAXN];
void getPrime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!notprime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
        {
            notprime[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    cin >> n;
    getPrime();
    cout << prime[0] << endl;
    return 0;
}