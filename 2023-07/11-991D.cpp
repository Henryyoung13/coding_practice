#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
string s[2];
int f[110][4];
 
void solve()
{
    cin >> s[0] >> s[1];
    int n = s[0].size();
    memset(f, -0x3f, sizeof f);
    for (int i = 1; i <= n; i ++ ) {
        int st = 0;
        for (int j = 0; j < 2; j ++ ) {
            if (s[j][i - 1] == 'X')
                st |= 1 << j;
        }
        if (i == 1) {
            f[i][st] = 0;
            continue;
        }
        for (int j = 0; j < 4; j ++ ) {
            f[i][st] = max(f[i][st], f[i - 1][j]);
        }
        for (int j = 0; j < 2; j ++ ) {
            if (!(st >> j & 1)) {
                f[i][st | (1 << j)] = f[i - 1][0] + 1;
            }
        }
        if (st == 0) {
            for (int j = 0; j < 3; j ++ )
                f[i][3] = max(f[i - 1][j] + 1, f[i][3]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i ++ )
        ans = max(ans, f[n][i]);
    cout << ans << '\n';
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
    return 0;
}