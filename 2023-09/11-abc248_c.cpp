/*
 * @Author       : young
 * @Date         : 2023-09-13 03:16:16
 * @LastEditTime : 2023-09-13 03:38:39
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 998244353;
int f[3000][55];
int n, m, k;

int main()
{
    cin >> n >> m >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            for (int u = k; u >= j; u -- ) {
                f[u][i] = (f[u][i] + f[u - j][i - 1]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = n; i <= k; i ++ ) {
        ans = (ans + f[i][n]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}