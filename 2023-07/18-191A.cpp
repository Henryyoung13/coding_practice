#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
const int N = 5e5 + 5;
string s;
int f[26][26];
 
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> s;
        int a = s[0] - 'a', b = s.back() - 'a';
        for (int j = 0; j < 26; j ++ ) {
            if (f[j][a] > 0) {
                f[j][b] = max(f[j][b], f[j][a] + (int)s.size());
            }
        }
        f[a][b] = max(f[a][b], (int)s.size());
    }
 
    int ans = 0;
    for (int i = 0; i < 26; i ++ ) {
        ans = max(f[i][i], ans);
    }
    cout << ans << endl;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();
    return 0;
}