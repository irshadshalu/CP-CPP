#include<vector>
using namespace std;

#define LSOne(i) (i&(-i))

typedef vector<int> vi;

class FenwickTree {
    private:
        int N;
        vi A, ft;

        void adjust(int k, int v) {
            for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
        }

        int rsq(int b) {                                        
            int sum = 0;
            for(; b > 0; b -= LSOne(b)) sum += ft[b];           // runs # no of 1's in binary representation of b
            return sum;
        }

    public:
        FenwickTree(const vi &arr) {
            A = arr;
            N = arr.size();
            ft.assign(N+1, 0);
            for(int i = 0; i < N; ++i)
                adjust(i+1, arr[i]);
        }

        int rsq(int a, int b) {                                 // range sum query O(log N) with indexes
            return rsq(b+1) - (a == 0? 0: rsq(a));
        }

        void update(int idx, int val) {                         // point update O(log N)
            adjust(idx+1, val - A[idx]);
        }
};

int main() {
    vi arr = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
    FenwickTree obj(arr);
    printf("RSQ(1, 3) = %d\n", obj.rsq(1, 3)); // answer = 17+13+19 = 49
    obj.update(4, 10); 
    printf("RSQ(4, 6) = %d\n", obj.rsq(4, 6)); // answer = 10+11+20 = 41
    return 0;
}