#include<vector>
using namespace std;

#define LSOne(i) (i&(-i))

typedef vector<int> vi;
typedef vector<vi> vvi;

class FenwickTree2D {
    private:
        int M, N;
        vvi mat, ft;

        void adjust(int x, int y, int v) {
            for(int i = x; i < (int)ft.size(); i += LSOne(i)) 
            for(int j = y; j < (int)ft[i].size(); j += LSOne(j))
                ft[i][j] += v;
        }

        int rsq(int x, int y) {                                        
            int sum = 0;
            for(int i = x; i > 0; i -= LSOne(i)) 
            for(int j = y; j > 0; j -= LSOne(j))
                sum += ft[i][j];
            return sum;
        }

    public:
        FenwickTree2D(const vvi &arr) {
            mat = arr;
            M = arr.size(); N = arr[0].size();
            ft.assign(M+1, vi(N+1, 0));
            for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                adjust(i+1, j+1, arr[i][j]);
        }

        int rsq(int i, int j, int k, int l) {                                 // range sum query in 2D O(log M * log N)
            return rsq(k+1, l+1) - rsq(k+1, j) - rsq(i, l+1) + rsq(i, j);
        }

        void update(int i, int j, int v) {                                    // point update O(log M * log N)
            adjust(i+1, j+1, v - mat[i][j]);
        }
};

int main() {
    vvi arr = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    }; // the original array
    FenwickTree2D obj(arr);
    printf("RSQ from (0,0) to (2,2) = %d\n", obj.rsq(0, 0, 2, 2)); // answer = 21
    printf("RSQ from (2,1) to (4,3) = %d\n", obj.rsq(2, 1, 4, 3)); // answer = 8
    obj.update(3, 2, 2);
    printf("RSQ from (2,1) to (4,3) = %d\n", obj.rsq(2, 1, 4, 3)); // answer = 10
    return 0;
}