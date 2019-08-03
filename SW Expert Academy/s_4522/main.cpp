#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    char input[34];
    char ans[2][15] = {"Not exist", "Exist"};
    for (int z = 1; z <= T; ++z) {
        cin >> input;
        int len;
        for (len = 0; input[len]; ++len);
        bool judge = true;
        for (int i = 0; i < len; ++i) {
            int temp =len-i-1;
            if(input[i] == input[temp]) {
                continue;
            } else if(input[i] == '?' || input[temp] == '?') {
                continue;
            } else {
                judge = false;
                break;
            }
        }

        cout << "#" << z << " " << ans[judge]<< "\n";
    }
    return 0;
}

