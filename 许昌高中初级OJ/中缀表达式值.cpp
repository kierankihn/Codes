#include <bits/stdc++.h>
using namespace std;
string input;
bool check()
{
    stack<char> tmp;
    for (long unsigned int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            tmp.push(')');
        }
        if (input[i] == ')')
        {
            if (!tmp.empty())
            {
                tmp.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (!tmp.empty())
    {
        return false;
    }
    for (long unsigned int i = 1; i < input.size(); i++)
    {
        if ((!isdigit(input[i])) && (!isdigit(input[i - 1])))
        {
            if ((input[i] == '(' && input[i - 1] != ')') || (input[i - 1] == ')' && input[i] != '('))
            {
                continue;
            }
            if (input[i - 1] == '(' && input[i] == '-')
            {
                continue;
            }
            return false;
        }
    }
    return true;
}
string change()
{
    stack<char> symbol;
    map<char, int> tmp;
    tmp['@'] = 0;
    tmp[')'] = 1;
    tmp['+'] = tmp['-'] = 2;
    tmp['*'] = tmp['/'] = 3;
    tmp['('] = -1;
    string res;
    for (long unsigned int i = 0; i < input.size(); i++)
    {
        long unsigned int k = i;
        while (isdigit(input[i]))
        {
            i++;
        }
        if(i>k)
        {
            res = res + ' ' + input.substr(k, i - k);
        }
        if (input[i] == '(')
        {
            symbol.push('(');
            continue;
        }
        if (input[i] == ')')
        {
            while ((!symbol.empty()) && (symbol.top() != '('))
            {
                res = res + ' ' + symbol.top();
                symbol.pop();
            }
            symbol.pop();
            continue;
        }
        while ((!symbol.empty()) && (tmp[symbol.top()] >= tmp[input[i]]))
        {
            res = res + ' ' + symbol.top();
            symbol.pop();
        }
        symbol.push(input[i]);
    }
    return res = res + ' ';
}
int count(string a)
{
    stack<int> num;
    long unsigned int k = 0;
    while (k < a.size() - 1)
    {
        string tmp = a.substr(k + 1, a.find(' ', k + 1) - k - 1);
        k = a.find(' ', k + 1);
        if (isdigit(tmp[0]))
        {
            num.push(stoi(tmp));
        }
        else
        {
            int res;
            int cz1, cz2;
            cz2 = num.top();
            num.pop();
            cz1 = num.top();
            num.pop();
            switch (tmp[0])
            {
            case '+':
                res = cz1 + cz2;
                break;
            case '-':
                res = cz1 - cz2;
                break;
            case '*':
                res = cz1 * cz2;
                break;
            case '/':
                res = cz1 / cz2;
                break;
            }
            num.push(res);
        }
    }
    return num.top();
}
int main()
{
    cin >> input;
    if (input[0] == '-')
    {
        input = "0" + input;
    }
    if (!check())
    {
        cout << "NO\n";
        return 0;
    }
    cout << count(change()) << endl;
    return 0;
}