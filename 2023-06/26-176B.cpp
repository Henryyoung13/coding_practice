/*
 * @Author       : young
 * @Date         : 2023-06-26 13:29:29
 * @LastEditTime : 2023-06-26 13:38:16
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

/*对着题解写的，待补*/

void solve() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    string ss = s + s;
    int c = 0, n = s.size();
    
    for (int i = 0; i < n; i ++ ) {
        if (ss.substr(i, n) == t)    ++ c;
    }
    ll f = (s == t), g = f ^ 1;
    while (k -- ) {
        ll f1 = (f * (c - 1) + g * c) % mod;
        ll g1 = (f * (n - c) + g * (n - c - 1)) % mod;
        f = f1, g = g1;
    }
    cout << f << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}