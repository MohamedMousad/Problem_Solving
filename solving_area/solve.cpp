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
vector<int> is_good(vector <int>& vec , int mid)
{
    int curr1 = 0 , curr2 = 0 ,limit = vec.size();
    for (int i = 0; i < limit ;i++)
    {
        curr1 += abs(vec[i] - (mid-1));
        curr2 += abs(vec[i] - (mid + 1));
    }
    return { curr1 < curr2 , min(curr1, curr2)};
}
int BS(vector <int>& vec)
{
    int l = 0, r = 2e9, mid = 0, ans = LLONG_MAX;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        vector<int> temp = is_good(vec, mid);
        if (temp[0])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        ans = min(ans , temp[1]);
    }
    return ans;
}
void solve()
{
    int n ;
    cin >> n;
    vector<int> a(n);
    cin(a);
    // if (a.size() == 1)
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    cout << BS(a) << endl;
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
