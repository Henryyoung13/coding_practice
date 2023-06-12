/*
推公式 f[i, j]表示移动到j，花费i次的方案数
为了方便计算，在这里取 a < b
由于条件四的限制，1 <=j< b
记上一次的位置为x，当x < j 时，显然|x - j| < |x - b|成立
当x > j时，需要满足|x - j| < |x - b|，即x在j、b间中点的左侧，有x <= (b + j - 1) / 2
综上 f[i][j] = f[i - 1][1] + ... + f[i - 1][(b + j - 1) / 2] - f[i - 1][j] （不能停在某个点上）
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, a, b, k;
const int N = 5010, MOD = 1e9 + 7;
int f[N], s[N];
void solve() {
    cin >> n >> a >> b >> k;
    if (a > b) {
        a = n + 1 - a;
        b = n + 1 - b;
    }
    f[a] = 1;
    int ans = 0;
    for (int i = 0; i < k; i ++ ) {
        for (int j = 1; j < b; j ++ )
            s[j] = (s[j - 1] + f[j]) % MOD;
        for (int j = 1; j < b; j ++ )
            f[j] = (s[(j + b - 1) / 2] - f[j] + MOD) % MOD;
    }
    for (int i = 1; i < b; i ++ ) {
        ans = (ans + f[i]) % MOD;
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