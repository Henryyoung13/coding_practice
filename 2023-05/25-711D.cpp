/*
 * @Author       : young
 * @Date         : 2023-05-25 11:22:16
 * @LastEditTime : 2023-05-25 12:08:04
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int a[N], times[N], sz[N], p[N], n;

ll quick_power(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % MOD;
    }
    b >>= 1;
    a = a * a % MOD;
  }
  return res;
}

int find(int x) {
  if (x != p[x])
    p[x] = find(p[x]);
  return p[x];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int pa = find(i), pb = find(a[i]);
    if (pa != pb) {
      p[pa] = pb;
      sz[pb] += sz[pa];
    }
  }
  ll ans = 1;
  for (int i = 1, clock = 1; i <= n; i++) {
    if (times[i])
      continue;
    int dep = 0;
    for (int x = i, start_time = clock; x >= 0; x = a[x]) {
      if (times[x]) {
        if (times[x] >= start_time) {
          dep = max(dep, clock - times[x]);
        }
        break;
      }
      times[x] = clock++;
    }
    if (dep == 0)
      continue;
    int k = sz[find(i)] - dep;
    ll t = (quick_power(2, dep) - 2 + MOD) % MOD;
    t = t * quick_power(2, k) % MOD;
    ans = ans * t % MOD;
  }
  cout << ans << '\n';
  return 0;
}