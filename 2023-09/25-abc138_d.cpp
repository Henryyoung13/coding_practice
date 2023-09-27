/*
 * @Author       : young
 * @Date         : 2023-09-25 08:51:57
 * @LastEditTime : 2023-09-25 08:58:24
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 2e5 + 5;
int n, q;
int v[N], ans[N];
vector<int> g[N];

void dfs(int u, int fa, int sum) 
{
    for (auto& j : g[u]) {
        if (j == fa)    continue;
        dfs(j, u, sum + v[u]);
    }
    ans[u] = sum + v[u];
}

int main()
{
    cin >> n >> q;

    for (int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < q; i ++ ) {
        int a, b;
        cin >> a >> b;
        v[a] += b;
    }
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i ++ ) {
        cout << ans[i] << ' ';
    }
    return 0;
}