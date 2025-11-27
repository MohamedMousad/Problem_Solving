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
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n); cin(a);
    for (int i = 0  , j = 0; i < n;){
        if ( i == 0){
            while (i < k){
                s.insert({a[i] , i});
                i++;
            }
        }
        else {
            s.insert({a[i] , i});
            s.erase({a[j] , j});
            j++;i++;
        }
        if (k&1)
        cout << s.find_by_order(k/2)->first << " ";
        else 
        cout << s.find_by_order(k/2 - 1)->first << " ";
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