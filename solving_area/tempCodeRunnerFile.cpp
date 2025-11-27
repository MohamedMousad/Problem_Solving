#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(s) s.begin(), s.end()
#define cin(vec)        \
    for (auto &i : vec) \
    cin >> i
#define int long long int
#define ll long long
#define ld long double
#define PI acos(-1)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>// set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int N = 2e5+5, mod = 1000000007;
const long long OO = 1e18;

void mousad()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // // put input file if needed as input in problem
    // freopen("closing.in", "r", stdin);
    // freopen("closing.out", "w", stdout);
    #ifndef ONLINE_JUDGE
    #define cout cerr
        cerr.tie(0);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stderr);
        // freopen("output.txt", "w", stdout);
    #endif
}
// Variadic print function for debugging
template <typename... Args>
void print(Args... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
// Overload for vector
template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}
//______________________________________________________________________________________//
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt0 = 0 , ans = 0;
        for (int l = 0 , r = 0 ; r < nums.size() ; r++){
            cnt0+=(nums[r] == 0);
            while (cnt0 > k && l <= r )
                cnt0-=(nums[l++] == 0);
            if (cnt0 < k )
                ans = max(ans , r - l + 1);
        }
        return ans;
    }
};
void solve() {
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    s.longestOnes(nums , 2);
}
signed main()
{
    mousad();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cerr << "Scenario #" << i  << ":"<< endl;
        solve();
    }
}