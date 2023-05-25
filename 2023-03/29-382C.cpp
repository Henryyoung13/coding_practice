/*
 * @Author       : young
 * @Date         : 2023-03-29 04:09:20
 * @LastEditTime : 2023-03-29 04:26:29
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, a[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 1)
    {
        puts("-1");
    }
    else if (n == 2)
    {
        int d = a[1] - a[0];
        if ((d & 1) == 0)
        {
            if (d)
            {
                cout << 3 << '\n';
                cout << a[0] - d << ' ' << a[0] + d / 2 << ' ' << a[1] + d << '\n';
            }
            else
            {
                cout << 1 << '\n';
                cout << a[0] << '\n';
            }
        }
        else
        {
            cout << 2 << endl;
            cout << a[0] - d << ' ' << a[1] + d << '\n';
        }
    }
    else
    {
        int mx = -2e9, mn = 2e9;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i < n; i++)
        {
            int diff = a[i] - a[i - 1];
            if (mx <= diff)
            {
                if (diff == mx)
                    cnt1++;
                else
                    cnt1 = 1;
                mx = diff;
            }
            if (mn >= diff)
            {
                if (diff == mn)
                    cnt2++;
                else
                    cnt2 = 1;
                mn = diff;
            }
        }
        // 如果本来就是等差数列
        if (mx == mn)
        {
            if (mn)
            {
                cout << 2 << '\n';
                cout << a[0] - mn << ' ' << a[n - 1] + mn << '\n';
            }
            else
            {
                cout << 1 << '\n';
                cout << a[0] << '\n';
            }
        }
        else if (mx == 2 * mn && cnt1 == 1 && cnt1 + cnt2 == n - 1)
        {
            // 如果添加一个数才为等差数列
            for (int i = 1; i < n; i++)
            {
                int diff = a[i] - a[i - 1];
                if (diff == mx)
                {
                    cout << 1 << '\n';
                    cout << a[i] - mn << '\n';
                    break;
                }
            }
        }
        else
        {
            // 添加一个数不能为等差数列
            cout << 0 << '\n';
        }
    }
    return 0;
}