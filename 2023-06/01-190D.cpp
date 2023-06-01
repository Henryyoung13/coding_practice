/*
 * @Author       : young
 * @Date         : 2023-06-01 03:57:11
 * @LastEditTime : 2023-06-01 04:07:04
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;
using ll = long long;
const int N = 4e5 + 5;
int T, a[N];

void solve() {
    int n, k;
    unordered_map<int, int> cnt;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i ++ ) {
        cin >> a[i];
        ++ cnt[a[i]];
        if (cnt[a[i]] >= k) {
            int p = j;
            while (cnt[a[i]] >= k) {
                -- cnt[a[p ++]];
            }
            ans += 1ll * (p - j) * (n - i);
            j = p;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}