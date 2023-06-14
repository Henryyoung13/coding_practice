#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N], n, t;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ )
        cin >> a[i];
    ll ans = 0;
    ll a0 = a[0];
    for (int i = 1; i < n; i ++ ) {
        ll d = a[i] - a[i - 1];
        ans += abs(d);
        // d < 0    表示后面比前面小 前缀--
        // d > 0    表示后面比前面大 后缀++
        // 这两种做法，相对距离不变
        if (d < 0) {
            a0 += d;
        }
    }
    // 把a0处理为0
    ans += abs(a0);
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}