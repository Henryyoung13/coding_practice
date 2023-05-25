/*
 * @Author       : young
 * @Date         : 2023-05-16 04:08:54
 * @LastEditTime : 2023-05-16 04:22:35
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int T, n;

int next(int x)
{
    return x + x % 10;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    int mx = -2e9, mn = 2e9;
    bool flag5 = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 5 == 0)
        {
            a[i] = next(a[i]);
            flag5 = true;
        }
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (flag5)
    {
        if (mx == mn)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    else
    {
        bool flag2 = false, flag12 = false;
        for (int i = 0; i < n; i++)
        {
            while (a[i] % 10 != 2)
            {
                a[i] = next(a[i]);
            }
            if (a[i] % 20 == 2)
                flag2 = true;
            else
                flag12 = true;
        }
        if (flag2 && flag12)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}