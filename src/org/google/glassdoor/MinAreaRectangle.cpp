#include<vector>
#include<utility>
#include<unordered_set>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

// rectanlge sides parallel to x and y axis
void smallestRectancle(vector<ii> &points) {
    ll mna = LONG_MAX;
    unordered_set<ll> sp;
    for(auto p: points) {
        sp.insert(((ll)p.first << 32) + p.second);
    }
    for(int i=0; i<points.size(); ++i)
    for(int j=1; j<points.size(); ++j) {
        ii u = points[i], v = points[j];
        // treat u, v as diagnol
        if((u.first == v.first || u.second == v.second)) continue;
        ll a = ((ll)u.first << 32) + v.second;
        ll b = ((ll)v.first << 32) + u.second;
        if(sp.find(a) == sp.end() || sp.find(b) == sp.end()) continue;
        mna = min(mna, abs(((ll)u.first - v.first)*((ll)u.second-v.second)));
    } 
    if(mna == LONG_MAX) printf("No rectangle found!");
    else printf("Minimun area = %lld\n", mna);
}

int main() {
    vector<ii> points = { ii(1,1), ii(1,3), ii(3,1), ii(3,3), ii(4,1), ii(4,3) };
    smallestRectancle(points);
    
    points = { ii(1,1), ii(1,3), ii(3,1), ii(3,3), ii(2,2) };
    smallestRectancle(points);
    return 0;
}