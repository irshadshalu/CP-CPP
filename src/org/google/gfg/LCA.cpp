/*
 *  Using Euler walk and Sparse table method
 */
#include<vector>
#include<cmath>
using namespace std;

typedef vector<int> vi;

int V;                                                                      // total nodes
vector<vi> AdjList;                                                         // adjacency list to represent tree

vi euler, depth;                                                            // euler path, corresponding depth array
vi fai;                                                                     // first appearance index of element in euler path

class SparseTable {
    private:
        int N; vi A;
        vector<vi> spt;

        // O(NlgN)
        void build() {
            for(int i = 0; i < N; ++i) spt[i][0] = i;                       // length 1

            for(int j = 1; (1<<j) <= N; ++j)                                // max length for segment is 2^j = N for i = 0
            for(int i = 0; i + (1<<j) - 1 < N; ++i) {                       // for i where [i ... i+(2^j)-1] can be accomodated
                int ptr = i + (1 << (j-1));                                 // start of next j-1 segment
                if(A[ spt[i][j-1] ] <= A[ spt[ptr][j-1] ]) 
                    spt[i][j] = spt[i][j-1];
                else 
                    spt[i][j] = spt[ptr][j-1];
            }
        }

    public:
        SparseTable(const vi &arr) {
            N = arr.size(); A = arr;
            int w = (int)ceil(log2(N));
            spt.assign(N, vi(w));

            build();
        }

        // O(1)
        int rmq(int i, int j) {
            int k = (int)floor(log2(j - i + 1));                            // largest k for which 2^k <= length of query
            int first = spt[i][k];                                          // segment starting from i of length k      
            int second = spt[j-(1<<k)+1][k];                                // segment ending at j of length k
            return (A[first] <= A[second]) ? first : second;
        }
}*obj;

void dfs(int cur, int prv, int lev) {
    if(fai[cur] == -1) 
        fai[cur] = euler.size();
    
    euler.push_back(cur);
    depth.push_back(lev);
    
    for(int v: AdjList[cur]) {
        if(v != prv) {
            dfs(v, cur, lev + 1);
            euler.push_back(cur);
            depth.push_back(lev);
        }
    }
}

void generateEulerPath() {
    fai.assign(V+1, -1); 
    dfs(1, 0, 0);
    // printf("euler = "); for(int e: euler) printf("%d ", e); printf("\n");
    // printf("depth = "); for(int d: depth) printf("%d ", d); printf("\n");
    // printf("fai = "); for(int i=1; i<V ; i++) printf("%d(%d) ", i, fai[i]); printf("\n");
}

void addEdge(int u, int v) {
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
}

void makeTree() {
    V = 8; AdjList.resize(V+1);
    addEdge(1,2);   addEdge(1,3); 
    addEdge(2,4);   addEdge(2,5); 
    addEdge(2,6);   addEdge(3,7); 
    addEdge(3,8);
}

// O(1)
int LCA(int u, int v) {
    if(u == v) return u;
    if(fai[u] > fai[v]) swap(u, v);
    return euler[obj->rmq(fai[u], fai[v])];
}

int main() {
    // freopen("LCA.out", "w", stdout);
    makeTree();
    generateEulerPath();

    obj = new SparseTable(depth);

    printf("LCA(6,7): %d\n", LCA(6,7)); 
    printf("LCA(6,4): %d\n", LCA(6,4));

    return 0;
}
