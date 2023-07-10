#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory>
using namespace std;
const int N = 110;
int n, a[N], f[N][3];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    memset(f, 0x3f, sizeof f);
    f[0][0] = f[0][1] = f[0][2] = 0;
    for (int i = 1; i <= n; i ++ ) {
        f[i][0] = min({f[i - 1][0], f[i - 1][1], f[i - 1][2]}) + 1;
        if (a[i] == 1 || a[i] == 3) {
            f[i][1] = min(f[i - 1][2], f[i - 1][0]);
        } 
        if (a[i] == 2 || a[i] == 3) {
            f[i][2] = min(f[i - 1][1], f[i - 1][0]);
        }
    }
    cout << min({f[n][0], f[n][1], f[n][2]}) << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}