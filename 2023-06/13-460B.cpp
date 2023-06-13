#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
int a, b, c;

ll quick_power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}
void solve() {
    cin >> a >> b >> c;
    vector<ll> ans;
    for (int i = 1; i <= 9 * 9; i ++ ) {
        ll x = b * quick_power(i, a) + c;
        int sum = 0, t = x;
        while (t) {
            sum += t % 10;
            t /= 10;
        }
        if (sum == i && x < 1e9) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}