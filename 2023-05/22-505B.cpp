#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <unordered_set>
using namespace std;

// dfs
const int N = 110, M = N << 1;
int h[N], e[M], w[M], ne[M], idx;
int n, m, T, ans;
bool vis[N];
unordered_set<int> S;
void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}


void solve() {
    int st, ed;
    cin >> st >> ed;
    ans = 0;
    function<bool(int, int)> dfs = [&](int u, int color) {
        if (u == ed) {
            return true;
        }
        vis[u] = true;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (vis[j]) continue;
            if (w[i] == color) {
                if (dfs(j, color))  return true;
            }
        }
        vis[u] = false;
        return false;
    };
    for (auto& color : S) {
        memset(vis, 0, sizeof vis);
        if (dfs(st, color))     ans ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
        S.insert(c);
    }
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}

// 并查集
const int N = 110;
int n, m;
struct Union{
    vector<int> p;
    Union(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (x != p[x])  p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        p[pa] = pb;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<Union> u(m + 1, Union(n + 1));
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        u[c].merge(a, b);
    }
    int T;
    cin >> T;
    while (T--) {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= m; i ++ ) {
            if (u[i].find(a) == u[i].find(b))   ans ++;
        }
        cout << ans << '\n';
    }
    return 0;
}