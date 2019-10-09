#include <iostream>

using namespace std;

char map[11][11];

int N, M;
int xw[] = {0,1,0,-1}, yw[] = {-1,0,1,0};
bool ans = false;

void dfs(int y, int x, int by, int bx, int w, int d) {
    int dy = y, dx = x, bdy = by, bdx = bx;
    if(d >= 10) return;
    while(map[dy][dx] != 'O' && map[dy + yw[w]][dx + xw[w]] != '#') {
        dy += yw[w]; dx += xw[w];
    }
    while(map[bdy][bdx] != 'O' && map[bdy + yw[w]][bdx + xw[w]] != '#') {
        bdy += yw[w]; bdx += xw[w];
    }
    
    if(map[dy][dx] == 'O') {
        if(map[bdy][bdx] != 'O') {
            ans = true;
            return;
        } else return;

    } 

    if(dy == bdy && dx == bdx) {
        if((abs(dy - y) + abs(dx -x)) > (abs(bdy - by) + abs(bdx -bx)) ) {
            dy -= yw[w]; dx -= xw[w];
        } else {
            bdy -= yw[w]; bdx -= xw[w];
        }
    }
    if(y == dy && x == dx && by == bdy && bx == bdx) return;


    if(w % 2) {
        dfs(dy, dx, bdy, bdx, 0, d +1);
        dfs(dy, dx, bdy, bdx, 2, d +1);
    } else {
        dfs(dy, dx, bdy, bdx, 1, d +1);
        dfs(dy, dx, bdy, bdx, 3, d +1);
    }
}

int main() {
    cin >> N >> M;
    int by, bx, ry, rx;
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map[i][j] == 'R') {
                ry= i; rx = j;
            }
            else if(map[i][j] == 'B') {
                by= i; bx = j;
            }
        }
    }    
    for(int i = 0; i < 4; ++i) 
        dfs(ry, rx, by, bx, i, 0);
    
    cout << ans << "\n";
    return 0;
}