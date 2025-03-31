#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    ordered_set s;
    int k, m;
    cin >> k >> m;
    int cnt = m;
    for (int i = 1; i <= k; i++)
    {
        s.insert(i);
    }
    while (!s.empty())
    {
        cnt %= s.size();
        cout << *s.find_by_order(cnt) << " ";
        s.erase(s.find_by_order(cnt));
        cnt += m;
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
// bool is_good(vector <int>& a , int k , int mid)
// {
//     int n = a.size() , sum = 0 , curr = 1;
//     for (int i = 0; i < n ;i++)
//     {
//         sum += a[i];
//         if (a[i] > mid)
//             return false;
//         if (sum > mid){
//             sum = a[i];
//             curr++;
//         }
//     }
//     return curr <= k ;
// }
// int BS(vector <int>& a , int k)
// {
//     int l = 0, r = 1, mid = 0, ans = LLONG_MAX;
//     while(!is_good(a, k , r))
//         r *= 2;
//     while (l <= r)
//     {
//         mid = l + (r - l) / 2;
//         if (is_good(a , k , mid))
//         {
//             r = mid - 1;
//             ans = mid;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return ans;
// }