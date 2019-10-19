#include <iostream>
#include <queue>

#define INSIDE ty < N && tx < M && ty >= 0 && tx >= 0

using namespace std;

char mm[50][51];
int checked[50][50];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int N, M;

struct stat {
    int y, x, k, d;
    bool operator == (const stat &o) const {
        return y == o.y && x == o.x;
    }
} init;


queue<stat> q;
void findMan() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(mm[i][j] == '0') {
                init = {i,j,512,0};
            }
        }
    }
}

bool isAbleToGo(int ty, int tx, int tk) {
    
    if(mm[ty][tx] == '#') return false;
    else if((checked[ty][tx] & tk) == tk) return false;
    else if(mm[ty][tx] >= 'A' && mm[ty][tx] <= 'F') {
        int lock = 1 << (mm[ty][tx] - 'A');
        if ((tk & lock) == lock) return true;
        else return false;
    }
    return true;
}

int bfs() {
    
    q.push(init);
    while(q.size()) {
        stat c = q.front();
        q.pop();
        int y = c.y, x = c.x, k = c.k, d= c.d;    
        if(mm[y][x] == '1')
         return d;
        for (int i = 0; i< 4; ++i) {
            int ty = y + dy[i], tx = x + dx[i], tk = k;    
            if((INSIDE) && isAbleToGo(ty, tx, tk)) {
                if(mm[ty][tx] >= 'a' && mm[ty][tx] <= 'f') {
                    tk |= (1 << (mm[ty][tx] - 'a'));
                }
                q.push({ty, tx, tk, d+1});
                checked[ty][tx] = tk;
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i< N; ++i) {
        cin >> mm[i];
    }
    findMan();

    cout << bfs() << "\n";

    return 0;
}