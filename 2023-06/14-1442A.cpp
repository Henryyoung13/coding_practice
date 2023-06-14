/*
 * @Author       : young
 * @Date         : 2023-06-14 08:51:02
 * @LastEditTime : 2023-06-14 08:54:48
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 3e4 + 5;
int a[N], n, t;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    ll a0 = a[0];
    for (int i = 1; i < n; i ++ ) {
        ll d = a[i] - a[i - 1];
        if (d < 0)  a0 += d;
    }
    if (a0 >= 0)  cout << "YES\n";
    else cout << "NO\n";
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