/*
难！！！
二分 + 贪心
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

typedef pair<int, int> PII;
typedef long long LL;
PII p[N];
int n, m, a[N], b;
LL s[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b;
        p[i] = {a[i], b};
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
        s[i] = s[i - 1] + a[i];
    LL ans = 0;
    if (n <= m)
        ans = s[m] - s[m - n];
    for (int i = 1; i <= m; i++)
    {
        int pos = lower_bound(a + 1, a + m + 1, p[i].second) - a;
        int num = n - (m - pos + 1);
        if (num < 0)
            continue;
        LL cur = s[m] - s[pos - 1] + 1ll * p[i].second * num;
        if (num && p[i].first < p[i].second)
            cur += p[i].first - p[i].second;
        if (ans < cur)
            ans = cur;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
