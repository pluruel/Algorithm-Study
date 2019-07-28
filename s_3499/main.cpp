#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N; cin >> T;
    char input[1000][81];
    for (int z = 1; z <= T; ++z) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> input[i];
        }
        int t = N/2, b = 0, temp;
        if(N % 2) ++t;

        cout << "#" << z << " ";
        for (int i = 0; i < N; ++i) {
            if(i % 2){
                temp = t++;
            }else  {
                temp = b++;
            }
            cout <<input[temp] << " ";
        }
        cout << "\n";
    }
}