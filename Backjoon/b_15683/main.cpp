//0315

#include <iostream>
#define INSIDE ty < N && tx < M && ty >= 0 && tx >= 0
#define INT_MAX 1 << 31 -1;

using namespace std;

struct cam {
    int x, y, s;
    cam(int _y, int _x, int _s) : x(_x), y(_y), s(_s){}
};

int sc[][4] {
    0,0,0,0,
    0,1,0,0,
    0,1,0,1,
    1,1,0,0,
    1,1,0,1,
    1,1,1,1,
};
int wy[] = {-1, 0, 1, 0};
int wx[] = {0, 1, 0, -1};

int N, M, m[8][8];

cam *cams[8];
int ac = 0;
int ans = INT_MAX;

int pos[8];

int test() {
    int tm[8][8] = {0,};
    int voids = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            tm[i][j] = m[i][j];
        }
    }
    
    for (int i = 0; i < ac; ++i) {
        for (int j = 0; j < 4; ++j) {
            int temp = (j + pos[i]) % 4;
            if(sc[cams[i]->s][temp]) {
                int ty = cams[i]->y + wy[j], tx = cams[i]->x + wx[j];
                while((INSIDE) && tm[ty][tx] != 6) {
                    if(!tm[ty][tx])
                        tm[ty][tx] = 7;
                    ty += wy[j]; tx += wx[j];
                }
            } 
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(!tm[i][j]) voids++;
        }
    }
    return voids;
}

void turncams(int depth) {
    if(depth == ac) {
        ans = min(test(), ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        pos[depth] = i;
        turncams(depth +1);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> m[i][j];
            if(m[i][j] > 0 && m[i][j] < 6) {
                cams[ac++] = new cam(i, j , m[i][j]);
            }
        }
    }

    
    turncams(0);

    cout << ans << "\n";

    return 0;
}