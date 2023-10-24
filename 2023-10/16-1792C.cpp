/*
 * @Author       : young
 * @Date         : 2023-10-16 06:52:37
 * @LastEditTime : 2023-10-16 07:20:57
 */

/*
操作1次 去掉1, n后 2~n-1有序
操作2次 去掉1, n, 2, n - 1后 3~n-2有序
记答案为k次 去掉1, ..., k, n - k + 1, ..., n后 k+1 ~ n-k有序

显然最多操作n/2次
如果k次可以满足，那么k+1次也可以满足，求最少则倒着枚举即可
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e5 + 5;
int t, n, a[N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        int u;
        cin >> u;
        a[u] = i;
    }
    int x = n / 2;
    while (x > 0 && a[x] < a[x + 1] && a[n - x] < a[n - x + 1]) {
        x --;
    }
    cout << x << '\n';
    
}
int main()
{
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}