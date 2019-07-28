#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long T, N, ans, ans2;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        cin >> N;
        ans = (N * (N+1)) / 2;
        ans2 = ans << 1;
        cout << "#" << z << " " << ans << " " << ans2 - N << " " << ans2 << "\n";
    }
    return 0;
}
