#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 19;
int d, i, k, p;
int value[MAXN + 5];
int main()
{
    memset(value, 0, sizeof(value));
    cin >> d >> i;
    k = (1 << (d - 1));
    for (int j = 1; j <= i; j++)
    {
        p = 1;
        while (p < k)
        {
            if (value[p])
            {
                value[p] = 0;
                p = p * 2 + 1;
            }
            else
            {
                value[p] = 1;
                p = p * 2;
            }
        }
    }
    cout << p << endl;
    return 0;
}