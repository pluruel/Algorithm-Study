#include <iostream>

using namespace std;

int N, K, map[20][20];

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}

int abs(int input) {
    return input > 0 ? input : -input;
}

bool isabletoConstruct(int pos, bool isrow) {
    int slope = 0, length = 1, pre, cur, diff; 
    if(isrow) pre = map[pos][0];
    else pre = map[0][pos];
    
    for (int i = 1; i < N; ++i) {
        if(isrow) cur = map[pos][i];
        else cur = map[i][pos];

        diff = cur- pre;
        if(abs(diff) > 1) {
            return false;
        } else if (!diff) {
            if(slope) slope++;
            else length++;
            slope %= K;
        } else {
            if(slope) {
                return false;
            }
            else if(diff == -1) {
                slope = 1; 
                length = 0;
            }
            else if (diff == 1 && length >= K) {
                length = 1;
                slope = 0;
            }
            else return false;
        }        
        pre = cur;
    }
    
    if(slope) return false;
    return true;
}

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short T;
    cin >> T;
    
    for (int z = 1; z <= T; ++z) {
        input();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += isabletoConstruct(i, true);
            ans += isabletoConstruct(i, false);
        }
        cout << "#" << z << " " << ans << "\n";
    }
    return 0;
}
