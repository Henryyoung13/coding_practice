#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];

void solve() {
    cin >> n;
    multiset<int> S;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i ++ ) {
        cin >> a[i];
        S.insert(a[i]);
        while (!S.empty() && (*S.rbegin() - *S.begin() > 1)) {
            S.erase(S.find(a[j ++]));
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}