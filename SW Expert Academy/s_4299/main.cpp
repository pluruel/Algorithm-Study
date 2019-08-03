#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    int standard = 11 * 24 * 60 + 11 * 60 + 11;
    for (int z = 1; z <= T; ++z) {
        int D, H, M;
        cin >> D >> H >> M;
        int min = D * 24 * 60 + H * 60 + M;
        int ans = min >= standard ? min - standard : -1;

        cout << "#" << z << " " << "\n";
    }
    return 0;
}



