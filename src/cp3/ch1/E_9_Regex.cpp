#include<string>
#include<regex>
#include<iostream>
using namespace std;

int main() {
    freopen("E_9_Regex.in", "r", stdin);
    freopen("E_9_Regex.out", "w", stdout);

    vector<regex> rlist;
    // all alphanumeric words \b
    rlist.push_back(regex("\\b\\w*\\b"));

    string str;
    while(getline(cin, str)) {
        printf("orginal = %s\n", str.c_str());
        for_each(rlist.begin(), rlist.end(), [str](regex r) {
            printf("modified = %s\n", regex_replace(str, r, "***").c_str());
        });
    }
}