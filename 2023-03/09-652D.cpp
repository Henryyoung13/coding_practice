#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n, cnt[N], tr[N];
map<PII, int> mp;

int query(int x)
{
    int res = 0;
    while (x)
    {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

void add(int x, int v)
{
    while (x < N)
    {
        tr[x] += v;
        x += x & -x;
    }
}
int main()
{
    cin >> n;
    int l, r;
    vector<int> alls;
    vector<PII> range(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        range[i] = {l, r};
        mp[range[i]] = i;
        alls.push_back(l);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    sort(range.begin(), range.end(), [&](PII &a, PII &b)
         {
        if (a.second != b.second)   return a.second < b.second;
        return a.first < b.first; });
    for (int i = 0; i < n; i++)
    {
        int l = range[i].first;
        l = lower_bound(alls.begin(), alls.end(), l) - alls.begin() + 1;
        cnt[mp[range[i]]] = i - query(l);
        add(l, 1);
    }
    for (int i = 0; i < n; i++)
        cout << cnt[i] << '\n';
    return 0;
}