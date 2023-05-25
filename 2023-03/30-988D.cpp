#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
unordered_set<int> S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        S.insert(a[i]);
    }
    int ans = 0, pos = -1, j1 = -1;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int &x = a[i];
        int cnt = 1;
        for (int j = 0; j < 31; j++)
        {
            int cnt1 = 1;
            if (S.count(x + (1 << j)))
            {
                cnt1++;
                if (S.count(x + (1 << j + 1)))
                    cnt1++;
            }
            cnt = max(cnt1, cnt);
        }
        if (ans < cnt)
        {
            ans = cnt;
            pos = i;
        }
    }

    cout << ans << '\n';
    cout << a[pos] << ' ';
    if (ans == 2)
    {
        for (int j = 0; j < 31; j++)
        {
            if (S.count(a[pos] + (1 << j)))
            {
                cout << a[pos] + (1 << j) << '\n';
                break;
            }
        }
    }
    else if (ans == 3)
    {
        for (int j = 0; j < 31; j++)
        {
            if (S.count(a[pos] + (1 << j)) && S.count(a[pos] + (1 << j + 1)))
            {
                cout << a[pos] + (1 << j) << ' ' << a[pos] + (1 << j + 1);
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}