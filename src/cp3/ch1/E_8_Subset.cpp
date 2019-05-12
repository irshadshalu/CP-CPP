#include<vector>
using namespace std;

int main() {
    freopen("E_8_Subset.out", "w", stdout);

    int N = 5;
    vector<int> arr;
    for(int i=0; i<N; ++i) arr.push_back(i);

    // 30 shift max before 2's complement starts
    printf("1<<30 = %d\n", 1<<30);
    
    // all subsets
    printf("N = %d\n", N);
    printf("Total subsets = %d\n", 1<<N);
    for(int ct=0; ct<(1<<N); ++ct) {
        printf("[");
        bool first = true;
        for(int j=0; j<N; ++j) if(ct & (1<<j)) {
            if(first) printf("%d", arr[j]), first=false;
            else printf(", %d", arr[j]);
        }
        printf("]\n");
    }
    return 0;
}