#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
int n, T;
 
void solve()
{
    cin >> n;
    // 取区间交集
    int mn = 0, mx = 1e9;
    bool ok = true;
    for (int i = 0, last = -1; i < n; i ++ ) {
        int x;
        cin >> x;
        if (last != -1) {
            if (last < x) {
                // 满足小于等于 diff 
                int diff = (x + last) / 2;
                mx = min(mx, diff);
            } else if (last > x) {
                // 满足大于等于 diff
                int diff = (x + last + 1) / 2;
                mn = max(mn, diff);
            }
            if (mn > mx) {
                ok = false;
            }
        }
        last = x;
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        cout << mn << '\n';
    }
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}