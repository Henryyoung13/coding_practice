#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2e5 + 10;
int l[N], r[N], ans[N];
int n, k, pos[N];

void del(int x)
{
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
        l[i] = i - 1;
        r[i] = i + 1;
    }
    int x = n;
    for (int step = 1; x; step++)
    {

        int t = step % 2 ? 1 : 2;
        int p = pos[x];

        while (ans[p])
        {
            p = pos[--x];
        }
        if (!x)
            break;
        for (int i = 0; i <= k & p <= n; i++)
        {
            ans[p] = t;
            del(p);
            p = r[p];
        }
        p = l[pos[x]];

        for (int i = 0; i < k && p; i++)
        {
            ans[p] = t;
            del(p);
            p = l[p];
        }
        x--;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}