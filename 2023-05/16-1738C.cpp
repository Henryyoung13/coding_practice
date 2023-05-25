/*
 * @Author       : young
 * @Date         : 2023-05-16 05:48:59
 * @LastEditTime : 2023-05-16 06:19:59
 */

// 博弈论

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110;
int T, n;
int dp[N][N][2][2];

int dfs(int i, int j, int state, int u)
{
    int &x = dp[i][j][state][u];
    if (x != -1)
        return x;
    if (!i && !j)
    {
        x = state ^ u ^ 1;
        return x;
    }
    x = 0;
    if ((i > 0 && !dfs(i - 1, j, state ^ u ^ 1, u ^ 1)) || (j > 0 && !dfs(i, j - 1, state, u ^ 1)))
    {
        x = 1;
    }
    return x;
}

void solve()
{
    cin >> n;
    int odds = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            odds++;
    }
    int events = n - odds;

    if (dfs(odds, events, 0, 0) == 1)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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