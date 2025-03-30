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
#define int long long int
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
    int n ;
    cin >> n;
    vector<int> a(n , 0) , freq(n);cin(a);
    set<pair<int,int> , greater<pair<int,int>>> s;
    for(int i = n-1 ; i >= 0 ;i--){
        while (!s.empty()){
            if (a[i] <s.begin()->first)
            {
                freq[s.begin()->second] = i+1;
                s.erase(s.begin());
            }
            else break;
        }
        s.insert({a[i] , i});
    }
    for (int i = 0 ; i < n;i++){
        cout << freq[i] << " ";
    }
    cout << endl;
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