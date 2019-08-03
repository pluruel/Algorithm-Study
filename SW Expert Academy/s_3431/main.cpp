#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    int L, U, X, ans;
    for (int z = 1; z <= T; ++z) {
        cin >> L >> U >> X;
        ans = 0;
        if(L > X) {
            ans = L-X;
        } else if (U < X) {
            ans = -1;
        }

        cout << "#" << z << " " << ans << "\n";
    }
    return 0;
}
