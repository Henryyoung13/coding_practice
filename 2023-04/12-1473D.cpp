#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;
typedef pair<int, int> pii;
struct Node
{
    int cur, mx, mn;
} pre[N];
int t, n, m;
pii suf[N];
char c[N];
void solve()
{
    cin >> n >> m;
    for (int i = 0, cur = 0; i < n; i++)
    {
        cin >> c[i];
        if (c[i] == '+')
            cur++;
        else
            cur--;
        pre[i + 1].cur = cur;
        pre[i + 1].mx = max(pre[i].mx, cur);
        pre[i + 1].mn = min(pre[i].mn, cur);
    }
    suf[n] = {0, 0};
    for (int i = n - 1, cur = 0, mx = 0, mn = 0; i >= 0; i--)
    {
        if (c[i] == '+')
            cur--;
        else
            cur++;
        mx = max(mx, cur);
        mn = min(mn, cur);
        suf[i] = {mx - cur, mn - cur};
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        auto p = pre[l - 1];
        auto s = suf[r];
        cout << max(p.mx, p.cur + s.first) - min(p.mn, p.cur + s.second) + 1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        solve();
    }
}