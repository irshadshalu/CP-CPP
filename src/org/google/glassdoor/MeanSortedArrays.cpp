#include<vector>
using namespace std;

void medInOneArray(vector<int> &ar, vector<int> &br) {
    int N = ar.size(), M = br.size();
    double med = -1;
    if(ar[N-1] <= br[0]) {
        int rem = (N+M)/2 - N;
        // printf("rem1 = %d\n", rem);
        if((N+M) % 2) med = (double)br[rem];
        else med = (br[rem] + br[rem-1]) / 2.0;
    } 
    else if(br[M-1] <= ar[0]) {
        int rem = (N+M)/2;
        // printf("rem2 = %d\n", rem);
        if(N+M % 2) med = br[rem];
        else med = (br[rem] + br[rem-1]) / 2.0;
    }
    printf("The median is %lf\n", med);
}

void sortedMean(vector<int> &ar, vector<int> &br) {
    if(ar.size() > br.size()) swap(ar, br);
    int N = ar.size(), M = br.size();
    if(ar[N-1] <= br[0] || br[M-1] <= ar[0]) {
        medInOneArray(ar, br);
        return;
    } 

    int low = 0, high = N - 1;
    int a_ptr = -1, b_ptr;
    double median = -1;
    while(low <= high) {
        a_ptr = (low + high) / 2;
        b_ptr = (N + M)/2 - a_ptr - 1;                // at most 1 more in first half incl. ar[0..a_ptr] & br[0..b_ptr] in case of N+M odd

        if(ar[a_ptr] <= br[b_ptr+1] && br[b_ptr] <= ar[a_ptr+1]) {
            if(N+M % 2) median= max(ar[a_ptr], br[b_ptr]);
            else median = (max(ar[a_ptr], br[b_ptr]) + min(ar[a_ptr+1], br[b_ptr+1])) / 2.0;
            break;
        }
        else if(ar[a_ptr] > br[b_ptr + 1]) high = a_ptr - 1;
        else low = a_ptr + 1;
    }
    printf("Mid ptrs at %d in ar and %d in br\n", a_ptr, b_ptr);
    printf("Median is %lf!\n", median);
}

int main() {
    vector<int> ar1 = {-5, 3, 6, 12, 15};
    vector<int> ar2 = {-12, -10, -6, -3, 4, 10};
    sortedMean(ar1, ar2);

    ar1 = {3, 5, 10, 11, 17};
    ar2 = {9, 13, 20, 21, 23, 27};
    sortedMean(ar1, ar2);

    ar1 = {10, 20, 30};
    ar2 = {40, 50, 60, 70, 80};
    sortedMean(ar1, ar2);

    ar1 = {90, 100};
    ar2 = {10, 20, 30, 40, 50};
    sortedMean(ar1, ar2);
}