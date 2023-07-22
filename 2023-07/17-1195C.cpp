#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
ll f[N][3];
int a[2][N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];
    
    for (int i = 1; i <= n; i ++ ) {
        f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
        f[i][1] = max(f[i - 1][0], f[i - 1][2]) + a[0][i];
        f[i][2] = max(f[i - 1][0], f[i - 1][1]) + a[1][i];
    }
    cout << max({f[n][0], f[n][1], f[n][2]});
    
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
    return 0;
}