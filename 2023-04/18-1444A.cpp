/*
 * @Author       : young
 * @Date         : 2023-04-18 04:42:59
 * @LastEditTime : 2023-04-18 05:49:30
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

typedef long long LL;

int T;
LL p, q;

void solve()
{
    cin >> p >> q;
    if (p % q)
        cout << p << '\n';
    else
    {
        LL ans = 0;
        for (LL i = 2, q0 = q; i <= q / i; i++)
        {
            if (q % i)
                continue;
            while (q % i == 0)
            {
                q /= i;
            }
            LL x = p;
            while (x % q0 == 0)
            {
                x /= i;
            }
            ans = max(ans, x);
        }
        if (q > 1)
        {
            while (p % q == 0)
            {
                p /= q;
            }
            ans = max(p, ans);
        }
        cout << ans << '\n';
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