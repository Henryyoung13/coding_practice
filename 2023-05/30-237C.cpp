/*
 * @Author       : young
 * @Date         : 2023-05-30 05:28:57
 * @LastEditTime : 2023-05-30 05:59:14
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int a, b, k;

bool check(int target, vector<int> &s) {
  for (int i = target; i <= b - a + 1; i++) {
    if (s[i] - s[i - target] < k) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> a >> b >> k;
  vector<bool> st(b + 1);
  vector<int> primes;
  st[1] = true;
  for (int i = 2; i <= b; i++) {
    if (!st[i]) {
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && primes[j] <= b / i; j++) {
      st[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  vector<int> s(b - a + 2);
  for (int i = a; i <= b; i++) {
    int u = i - a + 1;
    s[u] += s[u - 1];
    if (!st[i])
      s[u]++;
  }
  if (s[b - a + 1] < k) {
    cout << -1 << '\n';
    return;
  }

  int l = k, r = b - a + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid, s))
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}