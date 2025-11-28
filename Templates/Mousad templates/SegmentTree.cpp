//
// Created by RG on 11/28/2025.
//
class SegTree {
private:
#define right (idx<<1) + 2
#define left (idx<<1) + 1
    int size ,  n  ;
    // change ignore number , node and merge function to fit the problem
    static const int ign = 1e9+7; // put number that doesn't affect results
    // change it according to values stores in each node
    struct node {
        int val , occ;
        node(int val = ign, int occ = 1) : val(val), occ(occ) {};
    };
    vector<node> st;
    // change it to fit the problem
    node merge(node first , node second) {
        if (first.val < second.val)
            return node(first.val ,  first.occ);
        if (first.val > second.val)
            return node(second.val  , second.occ);
        return node(first.val , second.occ + first.occ);
    }
    void build(vector<int> &a , int l , int r , int idx) {
        int mid  = l + ((r-l)>>1) ;
        if (l == r) {
            if (l < n)
                st[idx] = a[l];
            return;
        }
        build(a , l , mid , left);
        build(a , mid + 1 , r , right);
        st[idx] = merge(st[left] , st[right]);
    }
    void set(int  i, int val , int l , int r , int idx ) {
        int mid = l + ((r - l) >> 1);
        if (r == l) {
            st[idx] = node(val);
            return;
        }
        if (i <= mid)
            set(i , val , l , mid , left );
        else
            set(i , val , mid+1 , r , right);
        st[idx] = merge(st[left] , st[right]);
    }
    node get(int  l, int r, int lq , int rq , int idx ) {
        if ( r < lq || l > rq)
            return {};
        if (l >= lq && r <= rq)
            return st[idx];
        int mid = l + ((r - l) >> 1);
        return merge(get(l, mid , lq  , rq , left),
                    get(mid + 1, r , lq  , rq , right));
    }
public:
    void init(vector<int>& a) {
        size = 1 , n = a.size();
        while (size < n) size<<=1;
        st.resize((size<<1));
        build(a , 0 , size - 1  , 0);
    }
    void set(int idx , int val) {
        return set(idx , val , 0 , size - 1, 0);
    }
    node get(int l   , int r) {
        return get( 0 , size - 1 , l , r, 0);
    }
#undef right
#undef left
};