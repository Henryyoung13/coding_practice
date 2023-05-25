#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int T, n;
string s;
void solve()
{
    cin >> n >> s;
    vector<int> a(n, -1), b(n, -1);
    int x = n;

    // min
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '<')
        {
            int j = i + 1;
            while (j < n - 1 && s[j] == '<')
                j++;
            for (int k = j - 1; k >= i; k--)
                a[k + 1] = x--;
            i = j - 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            a[i] = x--;
    }
    x = n;
    // max
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '<')
            b[i + 1] = x--;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
            b[i] = x--;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
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
