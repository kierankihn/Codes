#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10;
const int MAXL = 1 << (MAXN + 1);
int n;
string input;
char value[MAXL + 5];
char check(string a)
{
    char res;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != a[i - 1])
        {
            return 'F';
        }
    }
    if (a[0] == '1')
    {
        res = 'I';
    }
    else
    {
        res = 'B';
    }
    return res;
}
void solve(string a, int p)
{
    value[p] = check(a);
    if (a.size() == 1)
    {
        return;
    }
    solve(a.substr(0, a.size() / 2), p * 2);
    solve(a.substr(a.size() / 2, a.size() / 2), p * 2 + 1);
}
void print(int p)
{
    if (p < (1 << n))
    {
        print(p * 2);
        print(p * 2 + 1);
    }
    cout << value[p];
}
int main()
{
    cin >> n;
    cin >> input;
    solve(input, 1);
    print(1);
    cout << endl;
    return 0;
}