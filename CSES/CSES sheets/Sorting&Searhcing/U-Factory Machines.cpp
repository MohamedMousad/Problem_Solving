#include <bits/stdc++.h>
using namespace std;
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
bool is_good(vector <int>& vec , int k ,  int mid)
{
    int sum = 0 , n = vec.size();
    for (int i = 0 ; i < n ; i++)
    {
        sum+=(mid/vec[i]);
    }
    return sum >= k;
}
int BS(vector <int>& vec , int k)
{
    int l = 0, r = ULLONG_MAX, mid = 0, ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (is_good(vec , k , mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    int n , k;
    cin >> n >> k;
    vector <int> vec(n);
    cin(vec);
    cout << BS(vec , k) << endl;
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