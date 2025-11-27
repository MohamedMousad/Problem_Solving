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
int ign = 0 , n, m , k;
vector<vector<int>> sp;
int merge (int first , int second) {
    return first + second;
}
int query (int l , int r ) {
    int sz = (r - l +1) , ans = ign;
    for (int msk = 0 ; l <= r ; msk++ ){
        if (sz >> msk&1)
            ans = merge( ans , sp[msk][l]) , l+=(1<<msk);
    }
    return ans;
}
int queryO1(int m , int l , int r ) {
    int sz = (r - l +1);
    int msk = __lg(sz);
    return merge( sp[msk][l], sp[msk][r - (1<<msk) + 1]);
}
void  buildTable (vector<int> input) {
    int n = input.size();
    sp = vector<vector<int>> (__lg(n) + 1, vector<int>(n));
    sp[0] = input;
    for (int msk = 1 ; (1<<msk) <= n ; msk++) {
        for (int i = 0 ; i + (1<<msk) <= n ; i++) {
            int first = sp[msk-1][i] , second = sp[msk-1][i +  (1<<(msk - 1))];
            sp[msk][i] = merge(first , second);
        }
    }
}
void solve() {
    vector<int> a = {2 , 2 , 2, 2};
    buildTable(a);
    cout << query(3 , 3);
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