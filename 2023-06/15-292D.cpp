/*
 * @Author       : young
 * @Date         : 2023-06-15 03:06:10
 * @LastEditTime : 2023-06-19 09:08:39
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4 + 5, M = 510;

struct Node {
    int a, b;
}node[N];

int n, m;

int find(int x, vector<int>& fa) {
    if (x != fa[x]) fa[x] = find(fa[x], fa);
    return fa[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        cin >> node[i].a >> node[i].b;
    }
    vector<vector<int>> l(m + 2, vector<int>(n + 1)), r(m + 2, vector<int>(n + 1));    

    for (int i = 1; i <= n; i ++ ) {
        l[0][i] = i;
        r[m + 1][i] = i;
    }

    for (int i = 1; i <= m; i ++ ) {
        l[i] = l[i - 1];
        int pa = find(node[i].a, l[i]), pb = find(node[i].b, l[i]);
        if (pa != pb) {
            l[i][pa] = pb;
        }
    }
    
    for (int i = m; i; i -- ) {
        r[i] = r[i + 1];
        int pa = find(node[i].a, r[i]), pb = find(node[i].b, r[i]);
        if (pa != pb) {
            r[i][pa] = pb;
        }        
    }

    int k;
    cin >> k;
    while (k --) {
        int ll, rr;
        cin >> ll >> rr;
        int ans = 0;
        auto left = l[ll - 1], right = r[rr + 1];
        for (int i = 1; i <= n; i ++ ) {
            int pa = find(i, left), pb = find(i, right);
            // 如果本来就在同一个连通块里，没有必要重复合并
            if (find(pa, left) != find(pb, left)) {
                left[pa] = pb;
            }
        }
        for (int i = 1; i <= n; i ++ ) {
            if (find(i, left) == i) ans ++;
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}