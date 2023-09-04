/*
 * @Author       : young
 * @Date         : 2023-09-04 08:01:15
 * @LastEditTime : 2023-09-04 08:28:06
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
using ll = long long;
typedef pair<int, ll> pii;
const int N = 1e5 + 5;
ll L;
int N1, N2;
pii a[N], b[N];

int main()
{
    cin >> L >> N1 >> N2;
    for (int i = 1; i <= N1; i ++ ) {
        int v;
        ll l;
        cin >> v >> l;
        a[i] = {v, l};
    }
    for (int i = 1; i <= N2; i ++ ) {
        int v;
        ll l;
        cin >> v >> l;
        b[i] = {v, l};
    }
    ll l1 = 0, l2 = 0;
    ll ans = 0;
    int i = 1, j = 1;
    while (i <= N1 && j <= N2) {
        if (l1 + a[i].second < l2 + b[j].second) {
            if (a[i].first == b[j].first) {
                ans += l1 + a[i].second - max(l1, l2);
            }
            l1 += a[i].second;
            i ++;
        } else if (l1 + a[i].second > l2 + b[j].second) {
            if (a[i].first == b[j].first) {
                ans += l2 + b[j].second - max(l1, l2);
            }
            l2 += b[j].second;
            j ++;
        } else {
            if (a[i].first == b[j].first) {
                ans += l2 + b[j].second - max(l1, l2);
            }
            l1 += a[i ++].second;
            l2 += b[j ++].second;
        }
    }
    while (i <= N1) {
        if (a[i].first == b[N2].first) {
            ans += min(L, l1 + a[i].second) - max(L - b[N2].second, l1);
        }
        l1 += a[i].second;
        i ++;
    }
    while (j <= N2) {
        if (a[N1].first == b[j].first) {
            ans += min(L, l2 + b[j].second) - max(L - a[N1].second, l2);
        }
        l2 += b[j].second;
        j ++;
    }
    cout << ans << '\n';
    return 0;
}