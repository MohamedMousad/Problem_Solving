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
bool is_good(int a, int b, int k, int mid)
{
    return (max(0ll , (mid-a)/b) +  (mid/b) + (mid>=a) + 1) >= k;
}
int BS(int a ,int b , int k)
{
    int l = 0, r = 2e18, mid = 0 ,ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (is_good(a, b, k, mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
void solve()
{
    int n ; cin >> n;
    vector<int> a(n); cin(a);
    multiset<int> s;s.insert(a[0]);
    for (int i = 1 ; i < n ; i++)
    {
        auto it = s.upper_bound(a[i]);
        if (it == s.end())
            s.insert(a[i]);
        else
        {
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size( ) << endl;
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