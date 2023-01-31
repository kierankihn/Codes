#include <bits/stdc++.h>
using namespace std;
stack<char> a;
int main()
{
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i]=='(')
        {
            a.push(')');
        }
        else if(input[i]=='[')
        {
            a.push(']');
        }
        else
        {
            if ((!a.empty()) && (a.top() == input[i]))
            {
                a.pop();
            }
            else
            {
                cout<<"Wrong\n";
                return 0;
            }
        }
    }
    if(a.empty())
    {
        cout << "OK\n";
    }
    else
    {
        cout << "Wrong\n";
    }
    return 0;
}