/*
 * @Author       : young
 * @Date         : 2023-11-06 07:10:27
 * @LastEditTime : 2023-11-06 08:01:41
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 3010, MOD = 998244353;
int a[N], b[N];
int f[N][N], s[N], s1[N];

void solve()
{
    int n;
    cin >> n;
    // 状态定义 f[i, j]，j为当前为选的数为j的方案数
    // for (int i = 1; i <= n; i ++ ) {
    //     cin >> a[i];
    // }
    // for (int i = 1; i <= n; i ++ ) {
    //     cin >> b[i];
    // }
    // for (int i = 0; i < N; i ++ ) {
    //     s[i + 1] = s[i] + (i >= a[1] && i <= b[1]);
    // }    
    // for (int i = 2; i <= n; i ++ ) {
    //     memcpy(s1, s, sizeof s);
    //     memset(s, 0, sizeof s);
    //     for (int j = 0; j < N; j ++ ) {
    //         // for (int k = 0; k <= j; k ++ ) {
    //         //     f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
    //         // }
    //         if (j >= a[i] && j <= b[i]) f[i][j] = (f[i][j] + s1[j + 1]) % MOD;
    //         s[j + 1] = (s[j] + f[i][j]) % MOD;
    //     }
    // }
    // int ans = 0;
    // for (int i = a[n]; i <= b[n]; i ++ ) {
    //     ans = (ans + f[n][i]) % MOD;
    // }
    // cout << ans << '\n';

    // 状态定义 f[i, j]，j为当前为选的数 <= j的方案数
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++ ) {
        cin >> b[i];
    }
    for (int i = a[0]; i <= b[0]; i ++ ) {
        f[0][i] = i - a[0] + 1;
    }
    for (int i = 1; i < n; i ++ ) {
        for (int j = a[i]; j <= b[i]; j ++ ) {
            f[i][j] = (f[i][max(j - 1, 0)] + f[i - 1][min(j, b[i - 1])]) % MOD;
        }
    }
    cout << f[n - 1][b[n - 1]] << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}