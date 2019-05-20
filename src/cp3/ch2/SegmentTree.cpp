#include<vector>
using namespace std;

typedef vector<int> vi;

/*
 * TODO:
 * 1. Point update
 * 2. Insert new element(s)
 * 3. Delete element(s)
 * 4. Range update
 * 5. Lazy propagation
 */

class SegmentTree {
    private:
        int N;
        vi st, A;

        int left(int i) { return i<<1; }
        int right(int i) { return (i<<1)+1; }

        void build(int p, int l, int r) {
            if(l == r) st[p] = l;                           // only indexes
            else {
                build(left(p), l, (l+r)/2);
                build(right(p), (l+r)/2 + 1, r);
                int p1 = st[left(p)], p2 = st[right(p)];
                st[p] = (A[p1]<=A[p2])? p1: p2;
            }
        }

        int rmq(int p, int L, int R, int i, int j) {        
            if(i > R || j < L) return -1;
            if(L >= i && R <= j) return st[p];              // l,r within query

            int p1 = rmq(left(p), L, (L+R)/2, i, j);
            int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
            if(p1 == -1) return p2;
            if(p2 == -1) return p1;
            return (A[p1] <= A[p2])? p1: p2;
        }

    public:
        SegmentTree(const vi &arr) {
            A = arr; N = A.size();
            st.assign(4*N, 0);
            build(1, 0, N-1);
        }

        int rmq(int i, int j) {                             // range minimum query
            return rmq(1, 0, N-1, i, j);
        }
};

int main() {
    vi arr = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
    SegmentTree st(arr);
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 2
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5
    return 0;
}