/*
 * @Author       : yanghy
 * @Date         : 2023-03-17 03:59:48
 * @LastEditTime : 2023-03-17 05:43:18
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, k;
vector<int> cnt[10];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
        cnt[s[i] - '0'].push_back(i);
    int cost = INF;
    string ans;
    for (int i = 0; i <= 9; i++)
    {
        string t = s;
        int cost1 = 0, sum = cnt[i].size();
        if (sum >= k)
        {
            cout << 0 << endl;
            cout << s << endl;
            return 0;
        }
        for (int j = 1; j <= 9; j++)
        {
            if (i + j <= 9)
            {
                int m = cnt[i + j].size();
                for (int u = 0; u < m && sum < k; u++)
                {
                    t[cnt[i + j][u]] = '0' + i;
                    cost1 += j;
                    sum++;
                }
            }
            if (i - j >= 0)
            {
                int m = cnt[i - j].size();
                for (int u = m - 1; u >= 0 && sum < k; u--)
                {
                    t[cnt[i - j][u]] = '0' + i;
                    cost1 += j;
                    sum++;
                }
            }
        }
        if (cost1 < cost)
        {
            cost = cost1;
            ans = t;
        }
        else if (cost1 == cost)
            ans = min(ans, t);
    }
    cout << cost << '\n';
    cout << ans << '\n';
    return 0;
}