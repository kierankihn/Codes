#include <bits/stdc++.h>
using namespace std;
int pow_my(int a, int b)
{
    long long ans = pow(a, b);
    long long inf = 1e9;
    //    for(int i=1;i<=b;i++)
    //    {
    //        ans*=a;
    //        if(ans>inf)
    //        {
    //        	return -1;
    //		}
    //    }
    if (ans > inf)
    {
        ans = -1;
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << pow_my(a, b);
    return 0;
}
