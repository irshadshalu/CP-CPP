#include<vector>
#include<string>
#include<list>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi arr;

// for each element arr[i] find index of rightmost element in array which is greater than arr[i], if none print -1 as index
void solve() {
    int N = arr.size();
    vi RGE(N, -1);
    list<ii> left;
    for(int i = 0; i < N; ++i) left.push_back(ii(arr[i], i));

    for(int i = N-1; i >=0; --i) {
        int ele = arr[i];
        if(left.back().second == i) left.pop_back();

        for(list<ii>::iterator it = left.begin(); it != left.end(); ) {
            if(ele > (*it).first) {
                RGE[(*it).second] = i;
                it = left.erase(it);
            }
            else ++it;
        }

        if(left.empty()) break;
    }
    printf("arr = "); for(int x: arr) printf("%d\t", x); printf("\n");
    printf("rge = "); for(int x: RGE) printf("%s\t", (x == -1)? "-": to_string(arr[x]).c_str()); printf("\n");
}

int main() {
    arr = {34, 8, 10, 2, 3, 80, 30, 33, 1};
    solve();

    return 0;
}