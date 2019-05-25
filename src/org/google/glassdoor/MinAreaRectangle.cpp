#include<vector>
#include<utility>
#include<unordered_set>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

// rectanlge sides parallel to x and y axis
void smallestRectancle(vector<ii> &points) {
    auto hash=[](const ii& a){
        return (size_t)((ll)a.first << 32) + a.second;
    };
    auto equal=[](const ii& a, const ii& b){
        return ((a.first == b.first) && (a.second == b.second));
    };
    using PointsHash = unordered_set<ii, decltype(hash), decltype(equal)>;
    PointsHash pH(10, hash, equal);
    
    for(auto p: points) pH.insert(ii(p.first, p.second));
    ll ans = LONG_MAX;

    for(int i=0; i<points.size(); ++i)
    for(int j=1; j<points.size(); ++j) {
        ii u = points[i], v = points[j];
        // treat u, v as diagnol
        if((u.first == v.first || u.second == v.second)) continue;
        ii a = ii(u.first, v.second);
        ii b = ii(v.first, u.second);
        if(pH.find(a) == pH.end() || pH.find(b) == pH.end()) continue;
        ans = min(ans, abs(((ll)u.first - v.first)*((ll)u.second-v.second)));
    } 
    if(ans == LONG_MAX) printf("No rectangle found!");
    else printf("Minimun area = %lld\n", ans);
}

int main() {
    vector<ii> points = { ii(1,1), ii(1,3), ii(3,1), ii(3,3), ii(4,1), ii(4,3) };
    smallestRectancle(points);
    
    points = { ii(1,1), ii(1,3), ii(3,1), ii(3,3), ii(2,2) };
    smallestRectancle(points);
    return 0;
}