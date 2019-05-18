#include<vector>
using namespace std;

/*
 * divide an array into K contiguous partitions such that sum of maximum partition is minimum
 * ==> binary search the answer
 */

void parition(vector<int> &arr, int K) {
    int N = arr.size();
    int low = INT_MIN, high = 0;
    printf("K = %d \nArr = ", K);
    for(int i = 0; i < N; ++i) printf("%d ", arr[i]); printf("\n");
    for(int i=0; i<N; ++i) {
        if(arr[i]>low) low = arr[i];
        high += arr[i];
    }
    int mid = -1;
    while(low <= high) {
        mid = (low+high)/2;
        int parts = 1;
        int sum = 0;
        for(int i=0; i<N; ++i) {
            if(sum + arr[i] > mid) {
                parts++;
                sum = arr[i];
            }
            else sum += arr[i];
        }

        printf("low, mid, high, parts: %d %d %d %d\n", low, mid, high, parts);
        if(parts <= K) high = mid - 1;
        else low = mid + 1;
    }
    printf("Min sum = %d\n", mid);
}

int main() {
    vector<int> arr;
    arr = {10, 5, 3, 7, 1, 15};
    parition(arr, 3);
    return 0;
}