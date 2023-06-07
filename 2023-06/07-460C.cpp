#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5;

int n, m, w, a[N], d1[N];

bool check(int x) {
    memset(d1, 0, sizeof d1);
    for (int i = 0, d = 0, cnt = 0; i < n; i ++ ) {
        d += d1[i];
        if (a[i] + d >= x)  continue;
        int c = x - a[i] - d;
        d += c, d1[min(n + 1, i + w + 1)] -= c;
        cnt += c;
        if (cnt > w)    return false;
    }
    return true;
}

void solve() {
    cin >> n >> m >> w;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }

    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}