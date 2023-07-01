/*
 * @Author       : young
 * @Date         : 2023-06-27 03:10:45
 * @LastEditTime : 2023-06-27 03:23:43
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2010, mod = 998244353;

int f[N];

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    f[0] = m;
    for (int i = 1; i < n; i ++ )
        for (int j = i; j > 0; j -- ) {
            f[j] = (f[j] + 1ll * f[j - 1] * (m - 1)) % mod;
        }
    cout << f[k] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}