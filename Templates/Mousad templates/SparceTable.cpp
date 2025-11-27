int ign = 0;
vector<vector<int>> sp;
int merge (int first , int second) {
    return max(first ,  second);
}
int query (int l , int r ) {
    int sz = (r - l +1) , ans = ign;
    for (int msk = 0 ; l <= r ; msk++ ){
        if (sz >> msk & 1)
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