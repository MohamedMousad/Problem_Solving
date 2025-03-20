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
    int n , m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n;i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    for (int i = 0 , j = n - 1 ; i < j ;)
    {
        if (a[i].first + a[j].first < m)
        {
            i++;
        }
        else if (a[i].first + a[j].first > m)
        {
            j--;
        }
        else 
        {
            cout << a[i].second + 1 << " " << a[j].second+1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
