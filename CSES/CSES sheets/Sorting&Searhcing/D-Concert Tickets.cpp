#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define cin(vec)        \
    for (auto &i : vec) \
    cin >> i
#define int long long
#define ld long double
#define Ceil(a, b) (a / b) + (a % b != 0)
#define fill(i, a, b) for (long long i = a; i < b; i++)
#define rep(n) for (int i = 0; i < n; i++)
#define rrep(n) for (int i = n - 1; i >= 0; i--)
#define e 1e-9
void mousad()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    int n , m ;
    cin >> n >> m;
    multiset <int> a;
    vector<int> b (m);
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    cin(b);
    for (int i = 0 ; i < m;i++)
    {
        if (a.empty())
        {
            cout << -1 << endl;
            continue;
        }
        auto index = a.upper_bound(b[i]);
        if (index == a.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            index--;
            cout << *index << '\n';
            a.erase(index);
        }
    }
}
signed main()
{
    mousad();
    int n = 1;
    // cin >> n;
    while (n--)
    {
        solve();
    }
}