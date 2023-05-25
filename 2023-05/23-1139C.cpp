#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;
using ll = long long;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, k;
int p[N], sz[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b)
{
    int pa = find(a), pb = find(b);
    p[pa] = pb;
    sz[pb] += sz[pa];
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
        {
            merge(a, b);
        }
    }

    ll ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = ans * n % MOD;
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int fa = find(i);
        if (!vis[fa])
        {
            vis[fa] = true;
            ll t = 1;
            for (int i = 0; i < k; i++)
            {
                t = t * sz[fa] % MOD;
            }
            ans = (ans - t + MOD) % MOD;
        }
    }
    cout << ans << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}