#include <iostream>

using namespace std;

int N, W, ans = 0;
int m[100][100];

bool check(int p, bool ww) {
    int h = 1, l = 0;
    int pre = ww ? m[p][0] : m[0][p];
    
    for (int i = 1; i < N; ++i) {
        int cur = ww ? m[p][i] : m[i][p];
        if(abs(pre-cur) > 1) return false;
        if(pre > cur) {
            if(l != 0) 
                return false;
            l = 1; l %= W; h = 0; 
        } else if (pre < cur) {
            if(h < W) 
                return false;
            h = 1; l = 0;
        }
        else if (pre == cur) {
            if(l > 0) {
                l++; l %= W;
            } else if(l == 0) {
                h++;
            }
        }
        pre = cur;
    }   
    if(l != 0) 
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> W;

    for (int i= 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < N; ++i){
        ans += check(i, false);
        ans += check(i, true);
    }

    cout << ans << "\n";
    return 0;
}