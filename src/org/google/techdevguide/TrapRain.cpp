#include<vector>
using namespace std;

// using 2 pointers
// O(N): one iteration
// O(1): space complexity
void trap(const vector<int> &tower) {
    int rain = 0, i, j, lmx, rmx;
    i = 0; j = tower.size() - 1;
    lmx = rmx = 0;
    while(i < j) {
        if(tower[i] <= tower[j]) {
            if(tower[i] >= lmx) lmx = tower[i];
            rain += lmx - tower[i];
            i++;
        } else {
            if(tower[j] >= rmx) rmx = tower[j];
            rain += rmx - tower[j];
            j--;
        }
    }
    printf("rain = %d\n", rain);
}

int main() {
    vector<int> tower;
    tower = {1, 3, 2, 4, 1, 3, 1, 4, 5, 2, 2, 1, 4, 2, 2};
    trap(tower);
    
    tower = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    trap(tower);
    return 0;
}