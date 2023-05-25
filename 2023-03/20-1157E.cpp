/*
 * @Author       : yanghy
 * @Date         : 2023-03-20 02:40:48
 * @LastEditTime : 2023-03-20 12:04:00
 */
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <set>
// using namespace std;
// const int N = 2e5 + 10;

// int a[N], cnt[N], n;
// multiset<int> S;
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         S.insert(x);
//     }
//     for (int i = 0; i < n; i++)
//     {

//         auto it1 = S.lower_bound((n - a[i]) % n);
//         auto it2 = S.begin();
//         if (it1 == S.end())
//         {
//             cout << (*it2 + a[i]) << ' ';
//             S.erase(it2);
//         }
//         else
//         {
//             cout << (*it1 + a[i]) % n << ' ';
//             S.erase(it1);
//         }
//     }
//     cout << '\n';
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int N = 2e5 + 10;
int p[N], sz[N], n, a[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x)
{
    p[find(x)] = find(x + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sz[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (!sz[i])
            merge(i);
    }
    for (int i = 0; i < n; i++)
    {
        int u = find((n - a[i]) % n);
        if (u == n)
        {
            u = find(0);
        }
        cout << (u + a[i]) % n << ' ';
        --sz[u];
        if (!sz[u])
            merge(u);
    }
    cout << '\n';
    return 0;
}