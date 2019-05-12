#include<vector>
#include<algorithm>
using namespace std;

typedef vector<long> vl;

int dir[][2] = {
    {1, 1}, {1, 0}, {0, 1},
    {-1, 0}, {0, -1}, {-1, -1},
    {-1, 1}, {1, -1}
};

bool valid(int x, int y, int m, int n) {
    return x>=0 && x<m && y>=0 && y<n;
}

long countBG(int m, int n) {
    vector<vl> arr, brr;
    arr.assign(m, vl(n, 0));
    brr.assign(m, vl(n, 0));
    arr[m-1][0]=1;
    
    for(int ct=0; ct<n-1; ++ct) {
        for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j) {
            if(arr[i][j]>0)
            for(int v=0; v<8; v++) {
                int x=i+dir[v][0], y=j+dir[v][1];
                if(valid(x, y, m, n)) brr[x][y]+=arr[i][j];
            }
            arr[i][j]=0;
        }
        swap(arr, brr); 
        // printf("count = %d\n", ct);
        // print(arr);
    }  

    return arr[m-1][n-1];  
}

int main() {
    printf("%ld\n", countBG(4, 3));
    return 0;
}

// void print(const vector<vl> &arr) {
//     for(int i=0; i<arr.size(); ++i) {
//         for(int j=0; j<arr[i].size(); ++j) printf("%ld ", arr[i][j]);
//         printf("\n");
//     }
// }