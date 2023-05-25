/*
 * @Author       : yanghy
 * @Date         : 2023-03-14 04:09:36
 * @LastEditTime : 2023-03-14 04:42:06
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int t;
string s;

void solve()
{
    cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());
    string x, y;
    for (auto &c : s)
        if (c & 1)
            x += c;
        else
            y += c;

    if (x.empty() || y.empty())
    {
        cout << x + y << '\n';
    }
    else if (abs(x[0] - y.back()) != 1)
        cout << y + x << '\n';
    else if (abs(x.back() - y[0]) != 1)
        cout << x + y << '\n';
    else
        puts("No answer");
}
int main()
{
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}