/*
 * @Author       : young
 * @Date         : 2023-10-24 07:58:19
 * @LastEditTime : 2023-10-24 08:07:48
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N], b[N], n;

bool check(ll x) {
    ll sum = 0;
    for (int i = 0; i < n; i ++ ) {
        if (a[i] <= x)  continue;
        sum += b[i];
    }
    return sum <= x;
}

void solve()
{
    int mx = -1;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> b[i];
        sum += b[i];
    }
    ll l = 1, r = min(sum, 1ll * mx);
    while (l < r) {
        ll mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}