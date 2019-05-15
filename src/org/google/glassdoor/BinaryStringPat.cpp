#include<string>
#include<queue>
using namespace std;

void generate(string pat) {
    printf("Input: %s\n", pat.c_str());

    queue<string> qu;

    // improve
    queue<size_t> start;

    qu.push(pat); start.push(0l);
    while(!qu.empty()) {
        string str = qu.front();
        size_t index = start.front();

        // size_t is typedef unsigned long
        // npos is long constant
        size_t pos = str.find('?', index);

        if(pos != string::npos) {
            str[pos] = '0'; qu.push(str); start.push(pos);
            str[pos] = '1'; qu.push(str); start.push(pos);
        } else {
            printf("%s\n", str.c_str());
        }

        qu.pop(); start.pop();
    }

    printf("\n");
}

int main() {
    freopen("BinaryStringPat.out", "w", stdout);
    generate("10?0??");
    generate("??");
}