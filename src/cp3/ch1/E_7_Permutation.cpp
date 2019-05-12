#include<vector>
using namespace std;

void print_arr(const vector<char> &arr) {
    for_each(arr.begin(), arr.end(), [](char x) {
        printf("%c ", x);
    }); printf("\n");
}

int main() {
    freopen("E_7_Permutation.out", "w", stdout);

    int N = 5;
    vector<char> arr;
    for(int i=0; i<N; ++i)
        arr.push_back('A'+i);
    
    printf("%d! permutations:\n", N);
    do {
        print_arr(arr);
    } while(next_permutation(arr.begin(), arr.end()));

    return 0;
}