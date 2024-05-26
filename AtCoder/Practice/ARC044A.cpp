#include <bits/stdc++.h>
using namespace std;
bool checkPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x;
    cin >> x;
    if (x == 1)
    {
        cout << "Not Prime" << endl;
        return 0;
    }
    if (checkPrime(x))
    {
        cout << "Prime" << endl;
    }
    else if (x % 2 != 0 && x % 5 != 0 && x % 3 != 0)
    {
        cout << "Prime" << endl;
    }
    else
    {
        cout << "Not Prime" << endl;
    }
    return 0;
}