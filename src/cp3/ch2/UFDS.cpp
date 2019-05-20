#include<vector>
using namespace std;

typedef vector<int> vi;

class UFDS {
    private:
        int numSets;
        vi p, rank, setSize;
    public:
        UFDS(int N) {
            p.resize(N); for(int i=0; i<N; ++i) p[i] = i;
            rank.assign(N, 0); numSets = N; setSize.assign(N, 1);
        }
        int findSet(int i) {
            return (p[i] == i)? i: (p[i] = findSet(p[i]));      // path compression
        }
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);    
        }
        void unionSet(int i, int j) {
            if(!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) {                         // union by rank
                    p[y] = x;
                    setSize[x] += setSize[y];
                } else {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                    setSize[y] += setSize[x];
                }
                numSets--;
            }
        }
        int numDisjointSets() { return numSets; } 
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
};