#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
const int N = 1e5 + 10;
int n, m, d;
vector<int> g[N];
int d1[N], d2[N], up[N], p[N];
unordered_set<int> S;
// 实际上是计算每个点到怪兽的最远距离

// 先计算下面最大和次大
int dfs(int u, int fa)
{
    for (auto &ne : g[u])
    {
        if (ne != fa)
        {
            int dist = dfs(ne, u) + 1;
            if (S.count(ne) || dist > 1)
            {
                if (dist >= d1[u])
                    d2[u] = d1[u], d1[u] = dist, p[u] = ne;
                else if (dist > d2[u])
                    d2[u] = dist;
            }
        }
    }
    return d1[u];
}

void dfs1(int u, int fa)
{
    for (auto &ne : g[u])
    {
        if (ne != fa)
        {
            if (ne == p[u])
            {
                if (d2[u])
                    up[ne] = d2[u] + 1;
            }
            else
                up[ne] = d1[u] + 1;
            if (up[u] || S.count(u))
                up[ne] = max(up[ne], up[u] + 1);
            dfs1(ne, u);
        }
    }
    return;
}
int main()
{
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        S.insert(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    dfs1(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d1[i] <= d && up[i] <= d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
