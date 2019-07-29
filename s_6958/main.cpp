#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, M, input;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        cin >> N >> M;
        int max = -1, no = 0;;
        for (int i = 0; i < N; ++i) {
            int temp = 0;
            for (int j = 0; j < M; ++j) {
                cin >> input;
                temp += input;
            }
            if(temp == max) {
                no++;
            } else if (max < temp) {
                no = 1;
                max = temp;
            }
        }
        cout << "#" << z << " " << max << " " << no << " " << "\n";
    }
    return 0;
}
