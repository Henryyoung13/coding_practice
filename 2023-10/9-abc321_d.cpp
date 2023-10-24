#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, p;
int a[N], b[N];
ll s[N];
int main()
{
    cin >> n >> m >> p;
    ll ans = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i ++ ) {
        cin >> b[i];
    }
    sort(b, b + m);
    for (int i = 0; i < m; i ++ ) {
        s[i + 1] = s[i] + b[i];
    }

    for (int i = 0; i < n; i ++ ) {
        int pos = lower_bound(b, b + m, p - a[i]) - b;
        ans += 1ll * p * (m - pos) + s[pos] + 1ll * pos * a[i];
    }

    cout << ans << endl;
    return 0;
}