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
void solve()
{
    int n , q ;
    cin >> n >> q;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for (int i = 0 ; i < n;i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    int last = INT_MAX , rounds = 0 , size = 1 , j = 0;
    for (int i = 0 ; i < n;i++)
    {
        if(!(a[i].second > last))
        {
            while(j < i)
            {
                b[j++]= size;
            }
            size = 1;
            rounds++;
        }
        else
        {
            size++;
        }
        last = a[i].second;
    }
    while (j < n)
    {
        b[j++] = size;
    }
    for (int i = 0; i < q ;i++)
    {
        int x , y , diff = 0;  cin >> x >> y;
        x--; y--;
        bool xmerged = 0, ymerged = 0;
        int temp = a[x].second;
        a[x].second = a[y].second;
        a[y].second = temp;
        if ((x - 1 >= 0 && a[x-1].second < a[x].second) || (x + 1 < n && a[x+1].second > a[x].second ))
        {
            xmerged = true;
        }
        if ((y - 1 >= 0 && a[y-1].second < a[y].second) || (y + 1 < n && a[y+1].second > a[y].second))
        {
            ymerged = true;
        }
        if (xmerged && b[x] == 1)
        {
            diff--;
        }
        else if (!xmerged && b[x] > 1)
        {
            diff++;
        }
        if (ymerged && b[y] == 1)
        {
            diff--;
        }
        else if (!ymerged && b[y] > 1)
        {
            diff++;
        }
        cout << rounds + diff<< endl;
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
