/*
 * @Author       : young
 * @Date         : 2023-11-06 05:52:31
 * @LastEditTime : 2023-11-06 07:07:36
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, k, q;
int d[N], s[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> q;
    for (int i = 0; i < n; i ++ ) {
        int l, r;
        cin >> l >> r;
        d[l] ++, d[r + 1] --;
    }

    for (int i = 0; i < N; i ++ ) {
        d[i + 1] += d[i];
        if (d[i] >= k)  d[i] = 1;
        else d[i] = 0;
        s[i + 1] += s[i] + d[i];
    }

    for (int i = 0; i < q; i ++ ) {
        int l, r;
        cin >> l >> r;
        cout << s[r + 1] - s[l] << endl;
    }
    return 0;
}