/*
 * @Author       : young
 * @Date         : 2023-09-18 03:46:00
 * @LastEditTime : 2023-09-18 03:58:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
int n, q, x;
vector<int> pos[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> x;
        pos[x].push_back(i);
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r >> x;
        l --, r --;
        int left = lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin();
        int right = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin() - 1;
        int ans = max(right - left + 1, 0);
        cout << ans << '\n';
    }

    return 0;
}