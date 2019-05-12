#include<string>
#include<regex>
#include<iostream>
#include<utility>
using namespace std;

typedef pair<regex, string> prs;
vector<string> desc;

int main() {
    freopen("E_10_Regex.in", "r", stdin);
    freopen("E_10_Regex.out", "w", stdout);
    printf("https://regex101.com \n\n");

    vector<prs> rlist;
    
    desc.push_back("Replace all alphabetic words with asterisks: \\b[a-zA-Z]+\\b");
    rlist.push_back(prs(regex("\\b[a-zA-Z]+\\b"), "***"));

    desc.push_back("Replace all alphanumeric words incl. underscore: \\b\\w+\\b");
    rlist.push_back(prs(regex("\\b\\w+\\b"), "***"));

    desc.push_back("Replace word that starts with lower character followed by 2 digits: \\b[a-z]\\d{2}\\b");
    rlist.push_back(prs(regex("\\b[a-z]\\d{2}\\b"), "***"));

    string str;
    while(getline(cin, str)) {
        printf("Orginal := \n\t%s\n", str.c_str());
        auto it = desc.begin();
        for_each(rlist.begin(), rlist.end(), [str, &it](prs t) {
            printf("%s := \n\t%s\n", (*it).c_str(),regex_replace(str, t.first, t.second).c_str());
            ++it;
        });
        printf("\n");
    }
}