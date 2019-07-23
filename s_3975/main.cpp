#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    char ans[3][6] = {"ALICE", "BOB", "DRAW"};
    for (int z = 1; z <= T; ++z) {
        
        double a_total, a_win, b_total, b_win;
        cin >> a_win >> a_total >>b_win>> b_total;

        a_win /= a_total;
        b_win /= b_total;

        int ansno;
        if(a_win > b_win) {
            ansno = 0;
        } else if (b_win > a_win) {
            ansno = 1;
        } else {
            ansno = 2;
        }

        cout << "#" << z << " " << ansno[ans] << "\n";
    }
    return 0;
}

