/*
 * @Author       : young
 * @Date         : 2023-10-30 09:29:21
 * @LastEditTime : 2023-10-30 09:49:42
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int n, a[N];
ll f[N][2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    memset(f, 0, sizeof f);
    f[1][0] = a[1];
    f[1][1] = -a[1];

    for (int i = 2; i <= n; i ++ ) {
        f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] - a[i]);
        f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1] + a[i]);
    }
    cout << f[n][0] << endl;
    return 0;
}