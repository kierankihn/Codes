#include <bits/stdc++.h>
using namespace std;
string solve(string a, string b)
{
    if (a.size() == 1)
    {
        return a;
    }
    string la, lb, ra, rb, aa, ab;
    aa = "";
    ab = "";
    if (b.find(a[0]) > 0)
    {
        la = a.substr(1, b.find(a[0]));
        lb = b.substr(0, b.find(a[0]));
        aa = solve(la, lb);
    }
    if (b.size() - b.find(a[0]) - 1 > 0)
    {
        ra = a.substr(b.find(a[0]) + 1, b.size() - b.find(a[0]) - 1);
        rb = b.substr(b.find(a[0]) + 1, b.size() - b.find(a[0]) - 1);
        ab = solve(ra, rb);
    }
    return aa + ab + a[0];
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}