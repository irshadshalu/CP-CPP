#include<string>
#include<stack>
using namespace std;

string str;

void solve() {
    int ans = 0;
    stack<int> sk;
    sk.push(-1);

    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') sk.push(i);
        else {
            sk.pop();
            if(!sk.empty()) ans = max(ans, i-sk.top());
            else sk.push(i);
        }
    }
    printf("max valid substring of %s = %d\n", str.c_str(), ans);
}

int main() {
    str = "()))(";
    solve();

    str = ")(()(()(()))))";
    solve();

    return 0;
}