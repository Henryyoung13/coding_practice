/*
 * @Author       : young
 * @Date         : 2023-06-26 13:04:41
 * @LastEditTime : 2023-06-26 13:12:29
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 3010;

int a[N], b[N], l[N], r[N], n;

void solve() {
    cin >> n;

    for (int i = 0; i < n; i ++ )
        cin >> a[i];
    for (int i = 0; i < n; i ++ ) 
        cin >> b[i];
    for (int i = 0; i < n; i ++ ) {
        l[i] = 2e9;
        for (int j = 0; j < i; j ++ )
            if (a[j] < a[i])    l[i] = min(l[i], b[j]);
    }

    int ans = 2e9;
    for (int i = n - 1; i > 0; i -- ) {
        r[i] = 2e9;
        for (int j = n - 1; j > i; j -- )
            if (a[i] < a[j])    r[i] = min(r[i], b[j]);
        if (l[i] != 2e9 && r[i] != 2e9)
            ans = min(ans, l[i] + r[i] + b[i]);
    }
    if (ans == 2e9) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}