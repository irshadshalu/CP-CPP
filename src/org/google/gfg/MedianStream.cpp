#include<vector>
#include<queue>
using namespace std;

void median(vector<int> arr) {
    double med = arr[0];
    priority_queue<int> s;                                // default is max heap!!
    priority_queue<int, vector<int>, greater<int>> g;     // just like sort for reverse need to pass a > b
    s.push(arr[0]);
    int i = 1, N = arr.size();
    printf("Median at %d is: %.2lf\n", arr[0], med);
    while(i < N) {
        if(s.size() > g.size()) {
            if(arr[i] < med) {
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else g.push(arr[i]);
            med = (s.top() + g.top())/2.0;
        }
        else if (s.size() == g.size()) {
            if(arr[i] < med) {
                s.push(arr[i]);
                med = s.top();
            }
            else {
                g.push(arr[i]);
                med = g.top();
            }
        }
        else {
            if(arr[i] < med) s.push(arr[i]);
            else {
                s.push(g.top());
                g.pop();
                g.push(arr[i]);
            }
            med = (s.top() + g.top())/2.0;
        }
        printf("Median at %d is %.2lf\n", arr[i++], med);
    }
}

int main() {
    vector<int> arr = {5, 15, 10, 20, 3};
    median(arr);
    return 0;
}