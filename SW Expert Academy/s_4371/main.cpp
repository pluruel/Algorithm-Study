#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        int c[5001] = {0,}, ans = 0, N, temp;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> temp;
            if(i == 0) {
                continue;
            } else if (i == 1) {
                c[ans++] = temp-1;
            } else {
                bool judge =false;
                for (int j = 0; j < ans; j++) {
                    if(!((temp -1) % c[j])) {
                        judge = true;
                        break;
                    }
                }
                if (!judge) {
                    c[ans++] = temp-1;
                } 
            }
        }
        cout << "#" << z << " " << ans << "\n";
    }
    return 0;
}

