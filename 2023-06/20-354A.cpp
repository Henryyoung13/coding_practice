/*
 * @Author       : young
 * @Date         : 2023-06-20 08:42:42
 * @LastEditTime : 2023-06-20 09:09:05
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int n, l, r, ql, qr, a[N];
ll suf, pre;

/*前后缀分解，按照左侧出队的次数i，右侧出队则为n-i*/

/*
l = i, r = n - i

// case 1: 
// lrlr
// lrlrl ...

// case 2:
// lrlrl llll 2.1
// rlrll llll 2.2 
// 2.1 is better than 2.2

// case 3:
    equal to case 2
    
if abs(l - r) <= 1:
    cost = 0
else if (ll > rr + 1) {
    ...
}
else {
    ...
}
*/
void solve() {
    cin >> n >> l >> r >> ql >> qr;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        suf += a[i];
    }
    ll ans = suf * r + (n - 1) * qr;

    for (int i = 0; i < n; i ++ ) {
        suf -= a[i];
        pre += a[i];
        ll cost = pre * l + suf * r;
        int ll = i + 1, rr = n - ll;

        // abs(ll - rr) > 1
        
        if (ll > rr + 1) {
            cost += ql * (ll - rr - 1);
        } else if (rr > ll + 1) {
            cost += qr * (rr - ll - 1);
        }
        ans = min(ans, cost);
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