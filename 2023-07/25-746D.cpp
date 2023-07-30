#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
int n, k, a, b;
 
void solve()
{
    cin >> n >> k >> a >> b;
    char c1 = 'G', c2 = 'B';
    if (a > b) {
        swap(c1, c2);
        swap(a, b);
    }
    int m = (b + k - 1) / k;
    if (a >= m - 1 && a <= m * k) {
        string ans;
        for (int i = 1; i <= m; i ++ ) {
            int b1 = min(k, b - (m - i));
            int a1 = min(k, a - (m - 1 - i));
            if (b1 > 0 && b >= b1) {
                ans += string(b1, c2);
                b -= b1;
            }
            if (a1 > 0 && a >= a1) {
                ans += string(a1, c1);
                a -= a1;
            }
        }
        if (a > 0) {
            ans += string(a, c1);
        }
        cout << ans << '\n';
    } else {
        cout << "NO\n";
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}