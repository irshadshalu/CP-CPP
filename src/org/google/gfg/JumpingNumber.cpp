#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

// print jumping number <= x 
// jumping no where difference of adjacent digits is 1
// bfs 
// already sorted?
void solve(ll x) {
    queue<ll> qu;
    for(ll i = 1; i <= 9 && i <= x; ++i) qu.push(i);
    printf("jumping no.s less than equal to %lld = 0 ", x);
    while(!qu.empty()){
        ll f = qu.front(); qu.pop();
        if(f <= x) {
            printf("%lld ", f);
            int last = f % 10;
            if(last > 0) qu.push(f*10 + (last-1));
            if(last < 9) qu.push(f*10 + (last+1));
        }
    } printf("\n");
}

/*
 * Extension:
 * > Print in sorted order? use min heap
 */
void solve1(ll x) {
    priority_queue<ll, vector<ll>, greater<ll> > pq;                                // space between last two angular brackets is not required in c++11
    for(ll i = 1; i<=9 && i <= x; ++i) pq.push(i);
    printf("jumping no.s lesseq to %lld (sorted) = 0 ", x);
    while(!pq.empty()) {
        ll f = pq.top(); pq.pop();
        if(f <= x) {
            printf("%lld ", f);
            int last = f % 10;
            if(last > 0) pq.push(f*10 + (last-1));
            if(last < 9) pq.push(f*10 + (last+1));
        }
    } printf("\n");
}

int main() {
    solve(142LL);
    solve1(142LL);
    return 0;
}