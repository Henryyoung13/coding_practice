/*
    贪心 + 双指针
    先做LC881
 */
#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N];
 
void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        ans += a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] <= m) {
            l ++;
            if (l < r) {
                ans -= 2;
            } else {
                ans --;
            }
        }
        r --;
    }
    cout << ans + n << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}