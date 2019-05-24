#include<vector>
#include<stack>
#include<string>
using namespace std;

typedef vector<int> vi;

vi arr;

// for each element arr[i] find index of closest right element in array which is greater than arr[i], if none print -1 as index
void solve() {
    stack<int> sk;
    int N = arr.size();
    vi NGE(N);

    for(int i = N-1; i >= 0; --i) 
    if(sk.empty()) NGE[i] = -1, sk.push(i);
    else if(arr[i] >= arr[sk.top()]) {
        while(!sk.empty() && arr[i] >= arr[sk.top()]) sk.pop();
        if(!sk.empty() && arr[sk.top()] > arr[i]) NGE[i] = sk.top();
        else NGE[i] = -1;
        sk.push(i);
    }
    else {
        NGE[i] = sk.top();
        sk.push(i);
    }

    printf("arr = "); for(int x: arr) printf("%d\t", x); printf("\n");
    printf("nge = "); for(int x: NGE) printf("%s\t", (x == -1)? "-": to_string(arr[x]).c_str()); printf("\n");
}

int main() {
    arr = {34, 8, 10, 2, 3, 80, 30, 33, 1};
    solve();

    return 0;
}