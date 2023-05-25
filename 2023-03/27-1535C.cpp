/*
 * @Author       : young
 * @Date         : 2023-03-27 04:22:09
 * @LastEditTime : 2023-03-27 05:00:23
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
int T;
long long dp[N][2];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;
        if (s[i] == '0' || s[i] == '1')
        {
            int u = s[i] - '0';
            dp[i][u] = dp[i - 1][!u] + 1;
            ans += dp[i][u];
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1] + 1;
            ans += max(dp[i][0], dp[i][1]);
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
    {
        solve();
    }
    return 0;
}