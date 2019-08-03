#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        long long input, ans1, ans2;
        cin >> input;
        ans2 = ((input * (input + 1) - input) * 2 - 1);
        ans1 = ((input * (input - 1) - input) * 2 + 3);
        cout << "#" << z << " " << ans1 << " "  << ans2 << "\n";
    }
    return 0;
}
