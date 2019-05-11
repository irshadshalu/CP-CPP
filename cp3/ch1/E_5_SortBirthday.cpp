#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
    freopen("E_5_SortBirthday.in", "r", stdin);
    freopen("E_5_SortBirtdhay.out", "w", stdout);

    vector<iii> arr;
    int d, m, y;
    while(scanf("%d %d %d", &d, &m, &y)!=-1) {
        arr.push_back(iii(d, ii(m, y)));
    }

    // sort by asc. month, asc. day, and asc. age
    sort(arr.begin(), arr.end(), [](iii a, iii b) {
        if (a.second.first != b.second.first) return a.second.first < b.second.first;
        else if(a.first != b.first) return a.first < b.first;
        else return b.second.second < a.second.second;
    });

    for_each(arr.begin(), arr.end(), [](iii x) { 
        printf("%d %d %d\n", x.first, x.second.first, x.second.second);
    });
    return 0;
}