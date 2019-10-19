#include <iostream>
#include <queue>
#define INSIDE ty < N && tx < N && ty >= 0 && tx >= 0

int N;
char mm[50][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int checked[50][50];
int iy, ix, ip, ty, tx, tp;

using namespace std;

struct log {
    int y, x, pos, n;
    bool operator == (const log &cmp) const {
        return y == cmp.y && x == cmp.x && pos == cmp.pos;
    }
} sp, ep;


void search() {
    bool chkdb = false, chkde =false;
    for (int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j ) {
            if(mm[i][j]== 'B'&& !chkdb) {
                if(mm[i+1][j] == 'B') {
                    iy = i+1; ix = j; ip = 1; 
                } else if (mm[i][j+1] =='B') {
                    iy = i; ix = j+1; ip = 2;
                }
                chkdb = true;
                sp = {iy, ix, ip, 0};
            }
            if(mm[i][j]== 'E'&& !chkde) {
                if(mm[i+1][j] == 'E' ) {
                    ty = i+1; tx = j; tp = 1;
                } else if (mm[i][j+1] =='E') {
                    ty = i; tx = j+1; tp = 2;
                }
                chkde = true;
                ep = {ty, tx, tp};
            }
        }
    }
}

bool isMovable(int y, int x, int pos) {
    for (int i = -1; i < 2; ++i) {
        int ty, tx;
        if(pos == 1) {
            ty = y + i, tx = x;
            if(!(INSIDE) || mm[ty][tx] == '1') return false;
        } else {
            ty = y, tx = x + i;
            if(!(INSIDE) || mm[ty][tx] == '1') return false;
        }
    }
    return true;
} 

bool isTurnable(int y, int x) {
    for (int ty = y-1; ty < y + 2; ++ty) {
        for (int tx = x -1; tx < x +2; ++tx) {
            if(!(INSIDE)) return false;
            if(mm[ty][tx] == '1') return false;
        }
    }
    return true;
}

int bfs() {
    queue<log> q;
    q.push(sp); 
    checked[sp.y][sp.x] += sp.pos;

    while(q.size()) {
        log c = q.front();
        q.pop();
        int y = c.y, x = c.x, p = c.pos, n = c.n;
        if(c == ep) {
            return c.n;
        }
        for (int i = 0; i < 4; ++i) {
            int ty = y + dy[i], tx = x + dx[i];
            if((INSIDE) && isMovable(ty, tx, p) && (checked[ty][tx] & p) != p) {
                q.push({ty, tx, p, n+1});
                checked[ty][tx] |= p;
            }
        }
        int pp = p == 1? 2: 1;
        if(((checked[y][x] & pp) != pp) && isTurnable(y,x)) {
            q.push({y,x,pp, n+1});
            checked[y][x] |= pp;
        }
    }   
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;

    for (int i= 0; i < N; ++i) {
        cin >> mm[i];
    }
    search();

    cout << bfs() << endl; 

    return 0;
}