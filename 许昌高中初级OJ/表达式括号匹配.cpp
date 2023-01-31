#include <bits/stdc++.h>
using namespace std;
stack<char> a;
int main()
{
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            a.push(')');
        }
        if (input[i] == ')')
        {
            if ((!a.empty()) && (a.top() == input[i]))
            {
                a.pop();
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (a.empty())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}