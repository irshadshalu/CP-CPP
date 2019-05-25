#include<string>
#include<queue>
using namespace std;

typedef pair<string, int> psi;

void generate(string pat) {
    printf("Input: %s\n", pat.c_str());

    queue<psi> qu;

    qu.push(psi(pat,0));
    while(!qu.empty()) {
        string str = qu.front().first;
        int idx = qu.front().second;

        // size_t is typedef unsigned long
        // npos is long constant
        size_t pos = str.find('?', idx);

        if(pos != string::npos) {
            str[pos] = '0'; qu.push(psi(str, pos)); 
            str[pos] = '1'; qu.push(psi(str, pos));
        } else {
            printf("%s\n", str.c_str());
        }

        qu.pop();
    }

    printf("\n");
}

int main() {
    freopen("BinaryStringPat.out", "w", stdout);
    generate("10?0??");
    generate("??");
}