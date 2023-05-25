/*
 * @Author       : young
 * @Date         : 2023-05-08 01:58:21
 * @LastEditTime : 2023-05-08 02:11:25
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int main()
{
    cin >> n >> m;
    int ans = 0;

    while (m > n)
    {
        if (m % 2 == 0)
        {
            m /= 2;
        }
        else
            m++;
        ans++;
    }
    cout << ans + n - m << '\n';
    return 0;
}