#include<vector>
using namespace std;

typedef vector<int> vi;

/*
 * TODO:
 * 1. Insert new element(s)
 * 2. Delete element(s)
 */

// Segment Tree for Range Sum Query
class SegmentTree {
    private:
        int N;
        vi st, A, lazy;

        int left(int i) { return i<<1; }
        int right(int i) { return (i<<1) + 1; }

        void build(int p, int l, int r) {
            if(l == r) st[p] = A[l];                           
            else {
                build(left(p), l, (l+r)>>1);
                build(right(p), ((l+r)>>1) + 1, r);
                int p1 = st[left(p)], p2 = st[right(p)];
                st[p] = p1 + p2;
            }
        }

        int rsq(int p, int L, int R, int i, int j) {        
            if(i > R || j < L) return 0;

            if(lazy[p] != 0) {
                st[p] += (R-L+1) * lazy[p];
                if(L != R) lazy[left(p)] += lazy[p], lazy[right(p)] += lazy[p];
                lazy[p] = 0;
            }

            if(i <= L && R <= j) return st[p];    

            int p1 = rsq(left(p), L, (L+R)>>1, i, j);
            int p2 = rsq(right(p), ((L+R)>>1) + 1, R, i, j);
            return p1 + p2;
        }

        void update(int p, int L, int R, int i, int v) {
            if(i < L || i > R) return;
            st[p] += v;
            if(L == R) return;
            
            update(left(p), L, (L+R)>>1, i, v);
            update(right(p), ((L+R)>>1) + 1, R, i, v);
        }

        // lazy propagation
        void updateRange(int p, int L, int R, int i, int j, int v) {
            if(i > R || j < L) return;
            
            if(lazy[p] != 0) {
                st[p] += (R-L+1) * lazy[p];
                if(L != R) lazy[left(p)] += lazy[p], lazy[right(p)] += lazy[p];
                lazy[p] = 0;
            }
            
            if(i <= L && R <= j) {
                st[p] += (R-L+1) * v;
                if(L != R) lazy[left(p)] += v, lazy[right(p)] += v;
                return;
            }
            if(L == R) return;

            updateRange(left(p), L, (L+R)>>1, i, j, v);
            updateRange(right(p), ((L+R)>>1)+1, R, i, j, v);
            st[p] = st[left(p)] + st[right(p)];
        }

    public:
        SegmentTree(const vi &arr) {
            A = arr; N = A.size();
            st.assign(4*N, 0);
            lazy.assign(4*N, 0);
            build(1, 0, N-1);
        }

        // return sum from index i to j
        int rsq(int i, int j) {
            return rsq(1, 0, N-1, i, j);
        }

        // add v to index i
        void update(int i, int v) {
            update(1, 0, N-1, i, v);
        }

        // add v to all indices from i to j
        void update(int i, int j, int v) {
            updateRange(1, 0, N-1, i, j, v);
        }

        // normalize all elements O(N * logN)
        void printArr() {
            printf("{ ");
            for(int i = 0; i < N; ++i)
                printf("%d ", rsq(i, i));
            printf("} \n");
        }
};

int main() {
    vi arr = { 1, 2, 3, 0, 4, 5, -6 };        // the original array
    SegmentTree st(arr);
    
    printf("RSQ(1, 3) = %d\n", st.rsq(1, 3)); // ans = 2 + 3 + 0 = 5
    printf("RSQ(4, 6) = %d\n", st.rsq(4, 6)); // ans = 4 + 5 - 6 = 3
    
    st.update(6, 6);                          // arr = { 1, 2, 3, 0, 4, 5, 0 }
    
    printf("RSQ(4, 6) = %d\n", st.rsq(4, 6)); // ans = 4 + 5 + 0 = 9
    
    st.update(4, 6, -1);                      // arr = { 1, 2, 3, 0, 3, 4, -1 }
    
    printf("RSQ(2, 5) = %d\n", st.rsq(2, 5)); // ans = 3 + 0 + 3 + 4 = 10
    
    st.printArr();
    
    return 0;
}