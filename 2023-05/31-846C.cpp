#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
const int N = 5010;
int T, n, pre[N];
ll s[N];

// 前缀和 + 前后缀分解 O(n)
void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ )  {
        int x;
        cin >> x;
        s[i + 1] = s[i] + x;
        if (s[i + 1] > s[pre[i]]) {
            pre[i + 1] = i + 1;
        }
        else {
            pre[i + 1] = pre[i];
        }
    }
    int ii = 0, jj = 0, kk = 0;
    ll ans = -1e18, suf = s[n];
    int idx = n;
    for (int i = n; i >= 0; i -- ) {
        if (s[i] > suf) {
            suf = s[i];
            idx = i;
        }
        ll t = s[pre[i]] - s[i] + suf;
        if (t > ans) {
            ans = t;
            ii = pre[i];
            jj = i;
            kk = idx;
        }
    }
    cout << ii << ' ' << jj << ' ' << kk << '\n';
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