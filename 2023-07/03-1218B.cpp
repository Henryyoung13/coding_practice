/*
 * @Author       : young
 * @Date         : 2023-07-03 12:18:12
 * @LastEditTime : 2023-07-03 12:18:17
 */
#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
using ll = long long;
 
void solve()
{
    int n, x;
    cin >> n;
    ll f0 = 0, f1 = 0;
    ll ans0 = 0, ans1 = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> x;
        if (x > 0) {
            f1 += 1;
        } else {
            f1 = f0;
            f0 = f1 + 1;
        }
        ans0 += f0;
        ans1 += f1;
    }
    cout << ans0 << ' ' << ans1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}