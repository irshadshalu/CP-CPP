#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;

vi arr;

void solve(int X) {
    int N = arr.size();
    vector<iii> comb;
    for(int i = 0; i < N; ++i)
    for(int j = i + 1; j < N; ++j) {
        int s = arr[i] + arr[j];
        comb.push_back(iii(s, ii(i, j)));
    }

    sort(comb.begin(), comb.end(), [](iii a, iii b) {
        return a.first <= b.first;
    });

    int left = 0, right = comb.size() - 1;
    while(left < right) {
        int s = comb[left].first + comb[right].first;
        int a, b, c, d;
        a = comb[left].second.first; b = comb[left].second.second;
        c = comb[right].second.first; d = comb[right].second.second;
        if(s == X && a != c && a != d && b!=c && b!= d) {
            printf("%d + %d + %d + %d = %d\n", arr[a], arr[b], arr[c], arr[d], X);
            return;
        }
        else if(s == X) {
            if(left < N - 1 && comb[left+1].first == comb[left].first) ++left;
            else if(right > 0 && comb[right-1].first == comb[right].first) --right; 
            else ++left;
        }
        else if(s < X) ++left;
        else --right; 
    }
}

int main() {
    arr = {10, 20, 30, 40, 1, 2};
    solve(91); 
    return 0;
}