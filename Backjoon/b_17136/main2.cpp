#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

bool mm[10][10];
int p[] = {0,5,5,5,5,5};
int ans = MAX;

// 이런식의 구현이 들어간건 어쩄든 좌상의 색종이를 대 봐야 알 수 있기 때문이다
// 색종이를 대지 않은 위치는 고려해 볼 필요도 없다.
// 색종이 개수에 구애받지 않는 이유는 원하는 색종이를 대거나 고려하지 않을 경우, 해당 시행 자체를 무시하기 때문
// 조건이 되지 않으면 더이상 진행할 필요도 없게 만드는 것이 포인트.
// 색종이를 댈 수 없을때, 색종이를 대지 못할 때 더이상 시행을 해 보지 않는것이 포인트
// 가능한 모든 케이스를 체크할 수 있으면서, 의미없는 시행은 배제해야 함.

bool isAva(int y, int x, int w) {
    if (y + w > 10 || x + w > 10) return 0;
    for (int i = y; i < y+ w; ++i) {
        for (int j = x; j < x + w; ++j) {
            if(!mm[i][j]) return 0;
        }
    }
    return 1;
}

int n;

void dfs(int y, int x, int cnt) {
   
    if(y == 10) return;
    if(x == 10) {
        dfs(y+1, 0, cnt);
        return;
    }

    if(!mm[y][x]) {
        dfs(y, x+1, cnt);
        return;
    }

    for (int k = 5; k > 0; k--) {
        if(isAva(y,x,k) && p[k]) {
            for (int l = y; l < y + k; l++) {
                for (int m = x ; m < x + k; m++) {
                    mm[l][m] = 0;
                }
            }
            n -= k * k;
            p[k]--;
            if(n){
                dfs(y,x + k, cnt+ 1);
            } else {
                ans = min(ans, cnt);
            }
            n += k * k;
            for (int l = y; l < y + k; l++) {
                for (int m = x ; m < x + k; m++) {
                    mm[l][m] = 1;
                }
            }
            p[k]++;
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> mm[i][j];
            n += mm[i][j];
        }
    }
    if(n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    dfs(0,0,1);

    ans = ans == MAX ? -1 : ans;
    
    cout << ans << "\n";
    

    return 0;
}