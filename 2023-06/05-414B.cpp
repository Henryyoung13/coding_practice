/*
 * @Author       : young
 * @Date         : 2023-06-05 04:29:33
 * @LastEditTime : 2023-06-05 05:11:09
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 2001, MOD = 1e9 + 7;
int f[N][N], n, u;

vector<int> fac[N];

void init() {
    for (int i = 2; i < N; i ++ ) {
        if (fac[i].empty()) {
            for (int j = i; j < N; j += i)
                fac[j].push_back(i);
        }
    }
}

// O(nusqrt(u)) 非最优做法

void solve() {
    cin >> u >> n;
    // init();
    f[0][1] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= u; j ++ ) {
            for (int k = 1; k <= j / k; k ++ ) {
                if (j % k == 0) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
                    if (k != j / k) f[i][j] = (f[i][j] + f[i - 1][j / k]) % MOD;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= u; i ++ ) {
        ans = (ans + f[n][i]) % MOD;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}