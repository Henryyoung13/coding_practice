#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int h1[26][26];
int h2[26][26][26];
int T, n;

void solve()
{
    cin >> n;
    bool ok = false;
    memset(h1, 0, sizeof h1);
    memset(h2, 0, sizeof h2);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.size() == 1 || s[0] == s.back())
        {
            ok = true;
        }
        else if (s.size() == 2)
        {
            if (h1[s[1] - 'a'][s[0] - 'a'])
                ok = true;
            else
                h1[s[0] - 'a'][s[1] - 'a'] = 1;
        }
        else
        {
            if (h1[s[2] - 'a'][s[1] - 'a'] == 1)
                ok = true;
            else if (h2[s[2] - 'a'][s[1] - 'a'][s[0] - 'a'])
                ok = true;
            else
            {
                h1[s[0] - 'a'][s[1] - 'a'] = -1;
                h2[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'] = 1;
            }
        }
    }
    if (ok)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}