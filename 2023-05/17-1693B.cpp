#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int T, n, l[N], r[N];
int ans;

void solve()
{
    cin >> n;
    ans = 0;
    vector<int> g[n + 1];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }

    function<ll(int)> dfs = [&](int u)
    {
        ll sum = 0;
        for (auto &ne : g[u])
        {
            sum += dfs(ne);
        }
        if (sum < l[u])
        {
            ans++;
            sum = r[u];
        }
        return min(sum, (ll)r[u]);
    };

    dfs(1);
    cout << ans << '\n';
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