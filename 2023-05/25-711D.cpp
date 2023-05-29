/*
 * @Author       : young
 * @Date         : 2023-05-25 11:22:16
 * @LastEditTime : 2023-05-25 12:18:38
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int a[N], times[N], n;

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
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
          ans = ans * (quick_power(2, dep) - 2 + MOD) % MOD;
          n -= dep;
        }
        break;
      }
      times[x] = clock++;
    }
  }
  ans = quick_power(2, n) * ans % MOD;
  cout << ans << '\n';
  return 0;
}

/*
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int a[N], times[N], n;

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 1;
  int sz = n;
  for (int i = 1, clock = 1; i <= n; i++) {
    if (times[i])
      continue;
    int dep = 0;
    for (int x = i, start_time = clock; x >= 0; x = a[x]) {
      if (times[x]) {
        if (times[x] >= start_time) {
          dep = max(dep, clock - times[x]);
          ans = ans * (quick_power(2, dep) - 2 + MOD) % MOD;
          sz -= dep;
        }
        break;
      }
      times[x] = clock++;
    }
  }
  ans = quick_power(2, sz) * ans % MOD;
  cout << ans << '\n';
  return 0;
}
*/