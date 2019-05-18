#include<vector>
using namespace std;

typedef vector<int> vi;

void searchMat(vector<vi> &arr, int X) {
    bool flag = false;
    // start from top right O(M + N)
    int u = 0 , v = arr[0].size() - 1;
    while(u < arr.size() && v >= 0) {
        if(arr[u][v] == X) { flag = true; break; }
        else if(X > arr[u][v]) u++;
        else v--;
    }
    if(flag) printf("X found at (%d, %d)\n", u, v);
    else printf("X not found!\n");
}

int main() {
    vector<vi> arr = {{10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {27, 29, 37, 48}, 
                    {32, 33, 39, 50}};
    searchMat(arr, 29);
    return 0;
}