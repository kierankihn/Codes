#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    cin >> a >> b;
    if (b < 10)
    {
        cout << a << endl
             << b << endl
             << a * b << endl;
        return 0;
    }
    cout << a << endl
         << b << endl;
    c = b;
    while (b)
    {
        cout << a * (b % 10) << endl;
        b = b / 10;
    }
    cout << a * c << endl;
    return 0;
}