/*
 * @Author       : young
 * @Date         : 2023-05-24 07:04:19
 * @LastEditTime : 2023-05-24 07:10:17
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  vector<vector<pii>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  vector<vector<pii>> times(n + 1);
  for (int i = 1; i < n; i++) {
    int k, pre = -2;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      if (x > pre + 1) {
        times[i].push_back({x, x});
      } else {
        times[i].back().second = x;
      }
      pre = x;
    }
  }

  g[0].push_back({1, 0});

  vector<bool> st(n + 1);
  vector<int> dist(n + 1, INF);

  dist[0] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 0});
  while (pq.size()) {
    auto [t, u] = pq.top();
    pq.pop();
    if (u == n)
      break;
    if (st[u])
      continue;
    st[u] = true;

    for (auto [j, w] : g[u]) {
      int new_d = dist[u] + w;

      if (j < n && !times[j].empty()) {
        int l = 0, r = times[j].size() - 1;
        while (l < r) {
          int mid = l + r >> 1;
          if (times[j][mid].second >= new_d)
            r = mid;
          else
            l = mid + 1;
        }
        if (times[j][r].first <= new_d && times[j][r].second >= new_d)
          new_d = times[j][r].second + 1;
      }
      if (dist[j] > new_d) {
        dist[j] = new_d;
        pq.push({dist[j], j});
      }
    }
  }

  if (dist[n] == INF)
    dist[n] = -1;
  cout << dist[n] << '\n';

  return 0;
}