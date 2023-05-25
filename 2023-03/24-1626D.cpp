/*
 * @Author       : yanghy
 * @Date         : 2023-03-24 05:27:35
 * @LastEditTime : 2023-03-24 05:45:59
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;
int cnt[N], n, T;

int calc(int x)
{
    int t = x, high = 0;
    while (t)
    {
        high = t & -t;
        t -= t & -t;
    }
    if (high == x)
        return 0;
    return (high << 1) - x;
}

void solve()
{
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    int ans = 2e9;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= cnt[i]; k <<= 1)
        {
            int pos = lower_bound(cnt + 1, cnt + i, k + 1) - cnt - 1;
            int c1 = cnt[pos], c3 = cnt[n] - cnt[i], c2 = cnt[i] - c1;
            int x1 = 1, x2 = 1, x3 = 1;
            if (c1 > 0)
            {
                x1 += calc(c1) - 1;
            }
            if (c2 > 0)
            {
                x2 += calc(c2) - 1;
            }
            if (c3 > 0)
            {
                x3 += calc(c3) - 1;
            }
            ans = min(ans, x1 + x2 + x3);
        }
    }
    cout << ans << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
        solve();
    return 0;
}