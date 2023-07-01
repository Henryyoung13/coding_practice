/*
 * @Author       : young
 * @Date         : 2023-07-01 13:19:56
 * @LastEditTime : 2023-07-01 13:32:09
 */


// dp -> 转化成合并区间
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 1e4 + 5;
typedef pair<int, int> pii;
int T, n;
pii p[N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> p[i].second;
    }
    for (int i = 0; i < n; i ++ ) {
        cin >> p[i].first;
        p[i].first = p[i].second - p[i].first + 1;
    }
    sort(p, p + n);

    ll ans = 0;    
    // merge
    int l = -2e9, r = -2e9;
    for (int i = 0; i < n; i ++ ) {
        if (r == -2e9) {
            l = p[i].first;
            r = p[i].second;
        } else if (p[i].first <= r) {
            r = max(r, p[i].second);
        } else {
            ll len = r - l + 1;
            ans += 1ll * (len + 1) * len / 2;
            l = p[i].first;
            r = p[i].second;
        }
    }
    if (r != -2e9) {
        ll len = r - l + 1;
        ans += 1ll * (len + 1) * len / 2;
    }
    cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}