// 抄的方法二
#include <iostream>

using namespace std;

const int N = 1.5e6 + 5;
int a[N], n, m;
int cnt[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        if (i < m) {
            cnt[a[i]] ++;
        }
    }

    int ans = 0;
    while (cnt[ans] > 0) {
        ans ++;
    }

    for (int i = m; i < n; i ++ ) {
        cnt[a[i]] ++;
        int w = a[i - m];
        cnt[w] --;
        if (cnt[w] == 0 && w < ans) {
            ans = w;
        }
    }
    cout << ans << '\n';

    return 0;
}