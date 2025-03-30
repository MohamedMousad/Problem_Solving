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
    string s , ss; char c ;
    int n , k , sum = 0 , ans = 0;
    cin >> n >> k >> s;
    deque<int> a(n , 0) , b;cin(a);
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0 ; i < n ;){
        sum = 0;
        while(s[i] == 'B' && i < n){
            sum+=a[i];
            c = s[i];
            i++;
        }
        if (sum){
            ss.push_back(c);
            b.push_back(sum);
            sum = 0;
        }
        while (s[i] == 'R' && i < n){
            sum+=a[i];
            c = s[i];
            i++;
        }
        if(sum){
            ss.push_back(c);
            b.push_back(sum);
        }
    }
    if (!b.empty()){
        if (ss[ss.size() - 1] == 'R') b.pop_back();
    }
    if (!b.empty()){
        if (ss[0] == 'R') b.pop_front();
    }
    int needed = count(all(ss) , 'B');  
    int pen = needed - k;
    if (pen < 0){
        cout << 0 << endl;
    }
    else {
        for (int i = 0 ; i < b.size() ;){
            if ( i+1 < b.size()){
                pq.push(min(b[i] , b[i+1]));
                i+=2;
            }
            else {
                pq.push(b[i]);
                i++;
            }
        }
        while (pen-- && !pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}
signed main()
{
    mousad();
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
}
    // int n , ans = 0 , sum = 0; 
    // cin >> n; 
    // vector<pair<int,int>> a(n , {0,0}) , c(n , {0,0});
    // map<pair<int,int> , pair<bool,bool>> b;
    // ordered_set s , ss;
    // for (int i = 0 ; i < n ;i++){
    // cin >> a[i].first >> a[i].second;
    // }
    // c = a;
    // sort(all(a));
    // for (int i = n-1 ; i >= 0;i--){
    //     s.insert({a[i].second , i});
    //     int x = s.order_of_key(a[i].second+1);
    //     b[{a[i].first , a[i].second}].first = bool(x-1);
    // }
    // for (int i = 0 ; i < n;i++){
    //     ss.insert(a[i].second);
    //     int x = ss.insert(a[i].second);
    //     b[{a[i].first , a[i].second}].second = bool(ss.size() - x-1);
    // }
    // for (int i = 0 ; i < n ;i++){
        //     cout << b[{c[i].first , c[i].second}].first << " ";
    // }
    // cout << endl;
    // for (int i = 0 ; i < n ;i++){
    //     cout << b[{c[i].first , c[i].second}].second << " ";
    // }


    // int n , sum = 0;
    // cin >> n;
    // ordered_set a;
    // for (int i = 0 ; i < n ;i++){
    //     int x;cin >> x;
    //     a.insert({x , i+1});
    //     int y = a.order_of_key({x , 2e9});
    //     if (y == 1){
    //         cout << 0 << " ";
    //     }
    //     else {
    //         cout << a.find_by_order(a.order_of_key({x-1 , 2e9}))->second << " ";
    //     }
    // }
    // cout << endl;


    // string s ;int n , L = 0 , I  = 0, T = 0; cin >> n; cin >> s;
    // for (int i = 0 ; i < n;i++)
    // {
    //     if (s[i] == 'L'){
    //         L++;
    //     }
    //     else if (s[i] == 'I'){
    //         I++;
    //     }
    //     else if (s[i] == 'T'){
    //         T++;
    //     }
    // }
    // if (L == I == T){
    //     cout << 0 << endl;
    //     return;
    // }
    // else if (L == L + I + T || I == L + I + T || T == L + I + T){
    //     cout << -1 << endl;
    //     return;
    // }
    // else {
    //     int needl = max(L , max(I , T)) - L , needi = max(L , max(I , T)) - I , needt = max(L , max(I , T)) - T;
    //     if (needl + needi + needt > 2*n) {
    //         cout << -1 << endl; return;
    //     }
    // }