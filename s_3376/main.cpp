#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    cin >> T;

    long long ans[101] = {0,1,1,1,2,2,3,4,5,7};

    for(int i = 10; i <= 100; ++i) {
        ans[i] = ans[i-1] + ans[i-5];
    }    

    for (int z = 1; z <= T; ++z) {
        cin >> N;
        cout << "#" << z << " " << ans[N] << "\n";
    }
    return 0;
}
