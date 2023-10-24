/*
 * @Author       : young
 * @Date         : 2023-10-16 07:47:52
 * @LastEditTime : 2023-10-16 08:31:04
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
const int N = 2e5 + 5;

int t, n, k;
int a[N];

void solve()
{
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        ans += a[i] / k;
        a[i] %= k;
    }
    sort(a, a + n);
    for (int i = 0, j = n - 1; i < j; ) {
        if (a[i] + a[j] < k) {
            i ++;
        } else {
            ans += (a[i] + a[j]) / k;
            i ++;
            j --;
        }
    }
    cout << ans << '\n';
}

int main()
{
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}