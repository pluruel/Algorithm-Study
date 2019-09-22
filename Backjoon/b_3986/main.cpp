#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        stack<char> s;
        string ss;
        cin >> ss;
        
        for (int j = 0; j < ss.size(); ++j) {
            if(s.empty()) {
                s.push(ss[j]);        
                continue;
            }
            char tc = s.top();
            if(tc == ss[j]) {
                s.pop();
            } else {
                s.push(ss[j]);
            }
        }
        ans += s.empty();
    }
    cout << ans << "\n";
    return 0;
}