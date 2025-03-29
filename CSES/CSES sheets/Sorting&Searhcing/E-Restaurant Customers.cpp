#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>     
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define all(s) s.begin(), s.end()
#define cin(vec)        \
    for (auto &i : vec) \
    cin >> i
#define int unsigned long long int
#define ld long double
#define Ceil(a, b) (a / b) + (a % b != 0)
#define fill(i, a, b) for (long long i = a; i < b; i++)
#define rep(n) for (int i = 0; i < n; i++)
#define rrep(n) for (int i = n - 1; i >= 0; i--)
#define e 1e-9
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
    int n , ans= 0;cin>>n;
    vector<pair<int,int>> a(n , {0,0});
    ordered_set s;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    for(int i = 0 ; i < n ;i++)
    {
        s.insert(a[i].second);
        int temp = s.size() - s.order_of_key(a[i].first);
        ans = max(ans , temp);
    }
    cout << ans << endl;
}
signed main()
{
    mousad();
    int n = 1;
    //cin >> n;
    while (n--)
    {
        solve();
    }
}