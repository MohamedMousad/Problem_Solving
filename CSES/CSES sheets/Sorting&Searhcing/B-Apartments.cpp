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
    int n , m , k , cnt = 0;
    cin >> n >> m >> k;
    vector<int> a(n) , b(m) ;
    map <int, int> mp;
    cin(a);cin(b);
    sort(all(a));
    sort(all(b));
    for (int i = 0 , j = 0; i < n && j < m;)
    {
        if (a[i] - k <= b[j] && a[i] + k >= b[j])
        {
            i++;
            j++;
            cnt++;
        }
        else if (a[i] - k > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << cnt << endl;
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
