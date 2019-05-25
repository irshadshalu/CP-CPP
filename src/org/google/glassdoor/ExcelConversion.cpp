#include<string>
using namespace std;

// 1-A 26-Z 27-AA 52-AZ
void numberToExcel(int inp) {
    string col = "";
    int n = inp;
    while(n > 0) {
        int t = n % 26;
        if(t) {
            col.push_back('A' + t - 1);
            n /= 26;
        } else {
            col.push_back('Z');
            n = n/26 - 1;
        }
    }
    reverse(col.begin(), col.end());
    printf("%d = %s\n", inp, col.c_str());
}

void excelToNumber(string col) {
    int res = 0;
    int p = 1;
    reverse(col.begin(), col.end());
    for_each(col.begin(), col.end(), [&res, &p](char x) {
        res += p * (x - 'A' + 1);
        p *= 26;
    });
    printf("%s = %d\n", col.c_str(), res);
}

int main() {
    numberToExcel(702);
    numberToExcel(705);

    excelToNumber("ZZ");
    excelToNumber("AAC");
    return 0;
}