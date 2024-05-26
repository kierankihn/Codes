#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int t;
bool check(LL n, LL k)
{
    LL res = 0, tmp = n;
    while (n)
    {
        res += n % 3;
        n = n / 3;
    }
    // cout << res << endl;
    // cout << k << endl;
    // cout << (k - res) % 2 << endl;
    if (((k - res) % 2 == 0) && (res <= k) && (k <= tmp))
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> t;
    while (t--)
    {
        LL n, k;
        cin >> n >> k;
        if (check(n, k))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}