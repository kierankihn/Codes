#include <bits/stdc++.h>
using namespace std;
stack<char> a;
stack<char> b;
string input;
int main()
{
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '@')
        {
            while (!a.empty())
            {
                a.pop();
            }
        }
        else if (input[i] == '#')
        {
            a.pop();
        }
        else
        {
            a.push(input[i]);
        }
    }
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
    while(!b.empty())
    {
        cout<<b.top();
        b.pop();
    }
    cout << endl;
    return 0;
}