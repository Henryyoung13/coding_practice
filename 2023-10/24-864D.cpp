/*
 * @Author       : young
 * @Date         : 2023-10-24 08:09:56
 * @LastEditTime : 2023-10-24 08:45:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], cnt[N];
bool st[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int ans = 0;
    set<int> S;
    for (int i = 1; i <= n; i ++ ) {
        if (cnt[i] > 1) {
            ans += cnt[i] - 1;
        } 
    }
    cout << ans << '\n';
    for (int i = 1, cur = 1; i <= n; i ++ ) {
        if (cnt[a[i]] == 1) {
            continue;
        } 
        while (cnt[cur] > 0) {
            cur ++;
        }
        if (cur > a[i] && !st[a[i]]) {
            st[a[i]] = true;
            continue;
        }
        cnt[a[i]] --;
        a[i] = cur;
        cur ++;
    }
    for (int i = 1; i <= n; i ++ ) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}