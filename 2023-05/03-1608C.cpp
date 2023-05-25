#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5 + 5;

typedef pair<int, int> pii;
int T, n;
pii a[N], b[N];
bool st[N], ans[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        st[i] = false;
        ans[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    vector<int> g[n + 1];

    for (int i = 1; i < n; i++)
    {
        g[a[i].second].push_back(a[i + 1].second);
        g[b[i].second].push_back(b[i + 1].second);
    }
    queue<int> q;
    q.push(a[n].second);
    q.push(b[n].second);
    st[a[n].second] = true;
    st[b[n].second] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        ans[t] = true;
        for (auto &j : g[t])
        {
            if (!st[j])
            {
                q.push(j);
                st[j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}